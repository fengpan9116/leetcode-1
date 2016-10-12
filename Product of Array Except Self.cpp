class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        unsigned size = nums.size();
        if (size < 2) return nums;
        if (size == 2){
            reverse(nums.begin(), nums.end());
            return nums;
        }
        vector<int> res(size);
        res[0] = 1;
        for (int i = 1; i < size; i++){
            res[i] = res[i-1] * nums[i-1];
        }
        nums.push_back(1);
        for (int i = size-2; i >= 0; i--){
            nums[i+1] *= nums[i+2];
            res[i] *= nums[i+1];
        }
        return res;
    }
};