class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res = 0, mint = *min_element(nums.begin(), nums.end());
        for (auto i : nums) res += i - mint;
        return res;
    }
};