class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums_) {
        nums = nums_;
        curse(0);
        return res;
    }
private:
    void curse(int i){
        if (i == nums.size()){
            res.emplace_back(rest);
            return;
        }
        rest.emplace_back(nums[i]);
        curse(++i);
        rest.pop_back();
        curse(i);
    }
    vector<int> nums;
    vector<vector<int>> res;
    vector<int> rest;
};