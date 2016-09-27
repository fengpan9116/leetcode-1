class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = nums.front(), xor2 = 1;
        for (int i = 1; i < nums.size(); i++)
            xor1 ^= nums[i];
        for (int i = 2; i <= nums.size(); i++)
            xor2 ^= i;
        return xor1 ^ xor2;
    }
};