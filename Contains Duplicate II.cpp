class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> valdex;
        for (int i = 0; i < nums.size(); i++){
            auto f = valdex.find(nums[i]);
            if (f != valdex.end() && i-valdex[nums[i]] <= k)
                return true;
            else valdex[nums[i]] = i;
        }
        return false;
    }
};