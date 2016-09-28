class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool flag = !m_map.count(val);
        if (flag){
            m_vec.emplace_back(val);
            m_map[val] = m_vec.size() - 1;
        }
        return flag;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        bool flag = m_map.count(val);
        if (flag){
            auto i = m_map[val];
            m_map[m_vec.back()] = i; 
            iter_swap(m_vec.begin() + i, --m_vec.end()); 
            m_vec.pop_back();
            m_map.erase(val);
        }
        return flag;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        auto ran = rand() % m_vec.size();
        return m_vec[ran];
    }
private:
    unordered_map<int, int> m_map;
    vector<int> m_vec;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */