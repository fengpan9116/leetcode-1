// PLAYIN' WITH FIRE (TM)
class LRUCache{
public:
    LRUCache(int capacity_) : capacity(capacity_) {
        if (capacity_ <= 0) throw "...";
    }
    
    int get(int key) {
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
            get(key); // Shift this sucker up
            return;
        }
        if (numstored == capacity){
            auto h_key = head->key;
            key_to_node.erase(h_key);
            head = head->next;
            if (head) head->prev = nullptr;
            numstored--;
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
private:
    struct Cache {
        int key;
        int value;
        shared_ptr<Cache> next, prev;
        Cache(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
    };
    shared_ptr<Cache> head = nullptr, last = nullptr;
    int capacity;
    int numstored = 0;
    unordered_map<int, shared_ptr<Cache>> key_to_node;
};