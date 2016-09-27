class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int mask, res = 0, sum = 0;
        for (int i = 0; i < sizeof(int)*8; i++){
            sum = 0;
            mask = 1 << i;
            for (auto i : nums)
                if (i & mask) sum++;
            if (sum % 3) res |= mask;
        }
        return res;
    }
};