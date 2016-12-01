// PLAYIN' WITH FIRE MKII (TM)
// Friggin' O(1)
class LRUCache{
public:
    LRUCache() {}
    
    int get(bool getfirst, int key = 0) {
        if (getfirst) key = head->key;
        if (!key_to_node.count(key)) return -1;
        // Shift up
        auto node = key_to_node[key];
        if (node == last) return node->value;
        if (node->prev){
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        else{
            head = node->next;
            head->prev = nullptr;
        }
        node->prev = last;
        node->next = nullptr;
        last->next = node;
        last = node;
        return node->value;
    }
    
    void set(int key, int value) {
        // Detect collision
        if (key_to_node.count(key)){
            key_to_node[key]->value = value;
            get(false, key); // Shift this sucker up
            return;
        }
        auto cache = make_shared<Cache>(key, value);
        key_to_node[key] = cache;
        numstored++;
        if (!head){
            last = cache;
            head = cache;
        }
        else{
            cache->prev = last;
            last->next = cache;
            last = cache;
        }
    }
    
    void remove(int key){
        auto node = key_to_node[key];
        if (node->next) {
            node->next->prev = node->prev;
        }
        if (node->prev) node->prev->next = node->next;
        if (node == head && !node->next){
            head = nullptr;
            last = nullptr;
        }
        key_to_node.erase(key);
        numstored--;
    }
    
    void removeHead(){
        auto h_key = head->key;
        key_to_node.erase(h_key);
        head = head->next;
        if (head) head->prev = nullptr;
        numstored--;
    }
    
    struct Cache {
        int key;
        int value;
        shared_ptr<Cache> next, prev;
        Cache(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
    };
    shared_ptr<Cache> getHeadPtr() {return head;}
    
    int numstored = 0;
    shared_ptr<Cache> head = nullptr, last = nullptr;
    unordered_map<int, shared_ptr<Cache>> key_to_node;
};

class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (capacity <= 0) return -1;
        if (!key_to_freq.count(key)) return -1;
        auto freq = key_to_freq[key];
        auto fnode = freq_to_node[freq];
        auto value = fnode->lcache->get(false, key);
        updateCache(key, value);
        return value;
    }
    
    void updateCache(int key, int value) {
        auto lru = make_shared<LRUCache>(key, value);
        lru->set(key, value);
        shared_ptr<Fnode> fnode;
        int newfreq = key_to_freq.count(key) ? (key_to_freq[key]+1) : 0;
        // Check if new fnode exists
        if (freq_to_node.count(newfreq))
            fnode = freq_to_node[newfreq];
        else {
            fnode = make_shared<Fnode>(newfreq);
            freq_to_node[newfreq] = fnode;
            // Link
            if (newfreq == 0) {
                if (!head) {
                    head = fnode;
                    last = fnode;
                }
                else {
                    fnode->next = head;
                    head->prev = fnode;
                    head = fnode;
                }
            }
            else {
                auto oldfnode = freq_to_node[newfreq-1];
                auto oldnext = oldfnode->next;
                oldfnode->next = fnode;
                fnode->next = oldnext;
                fnode->prev = oldfnode;
                if (oldnext) oldnext->prev = fnode;
            }
        }
        // Old cache
        if (newfreq != 0) {
            // Remove node from old fnode
            auto oldfnode = freq_to_node[newfreq-1];
            oldfnode->lcache->remove(key);
            // Check if empty
            if (oldfnode->lcache->head == nullptr){
                if (oldfnode->next) {
                    oldfnode->next->prev = oldfnode->prev;
                }
                if (oldfnode->prev) oldfnode->prev->next = oldfnode->next;
                if (oldfnode == head && !oldfnode->next){
                    head = nullptr;
                    last = nullptr;
                }
                freq_to_node.erase(newfreq-1);
            }
        }
        // Add cache to new fnode
        fnode->lcache->set(key, value);
        key_to_freq[key] = newfreq;
    }
    
    void set(int key, int value) {
        if (capacity <= 0) return;
        if (numstored == capacity){
            // Insert first
            updateCache(key, value);
            // Remove oldest
            auto rmkey = head->lcache->getHeadPtr()->key;
            auto rmfreq = head->freq;
            head->lcache->removeHead();
            key_to_freq.erase(key);
            // Remove empty fnode
            if (!head->lcache->getHeadPtr()){
                freq_to_node.erase(rmfreq);
                head = head->next;
                head->prev = nullptr;
            }
        }
        else {
            updateCache(key, value);
            numstored++;
        }
    }
    
private:
    struct Fnode {
        int freq;
        shared_ptr<Fnode> next, prev;
        shared_ptr<LRUCache> lcache;
        Fnode(int f) : freq(f), next(nullptr), prev(nullptr), lcache(nullptr) {}
    };
    int capacity;
    int numstored = 0;
    shared_ptr<Fnode> head = nullptr, last = nullptr;
    unordered_map<int, int> key_to_freq;
    unordered_map<int, shared_ptr<Fnode>> freq_to_node;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.set(key,value);
 */