class Solution {
public:
    Solution(vector<int> nums) {
        srand(time(0));
        for (int i = 0; i < nums.size(); i++)
            val_to_idx.insert(make_pair(nums[i], i));
    }
    
    int pick(int target) {
        auto cnt = val_to_idx.count(target);
        auto it = val_to_idx.find(target);
        advance(it, rand() % cnt);
        return it->second;
    }
private:
    unordered_multimap<int, unsigned> val_to_idx;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */