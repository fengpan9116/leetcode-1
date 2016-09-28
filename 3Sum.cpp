class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-1; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1, k = nums.size()-1;
            while (j < k){
                if (nums[i] + nums[j] + nums[k] > 0) k--;
                else if (nums[i] + nums[j] + nums[k] < 0) j++;
                else{
                    vector<int> rest({nums[i], nums[k], nums[j]});
                    res.emplace_back(rest);
                    j++; k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return res;
    }
};