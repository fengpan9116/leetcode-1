class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> val_to_idx;
        for (int i = 0; i < nums.size(); i++){
            if (val_to_idx.count(target-nums[i])) 
                return {val_to_idx[target-nums[i]], i};
            val_to_idx[nums[i]] = i;
        }
        return {-1, -1};
    }
};