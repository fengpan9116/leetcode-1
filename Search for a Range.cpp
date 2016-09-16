class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        auto it = find(nums.begin(), nums.end(), target);
        if (it == nums.end()) return {-1, -1};
        res.emplace_back(it-nums.begin());
        while(it != nums.end()){
            if (*it != target) break;
            ++it;
        }
        res.emplace_back(it-nums.begin()-1);
        return res;
    }
};