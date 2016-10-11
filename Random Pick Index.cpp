class Solution {
public:
    Solution(vector<int> nums_) {
        srand(time(0));
        nums = nums_;
    }
    
    int pick(int target) {
        vector<unsigned> idx;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == target) idx.emplace_back(i);
        return idx[rand() % idx.size()];
    }
private:
    vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */