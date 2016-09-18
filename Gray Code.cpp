/*
BASE CASE:
000
1st(2^0):
001

2nd(2^1):
011
010

3rd(2^2):
110
111
101
100
*/
#include <bitset>
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<bitset<sizeof(int)*8>> bits;
        vector<int> res;
        bits.push_back(0);
        for (int i = 0; i < n; i++){
            auto lastpos = bits.size() - 1;
            for (int j = 0; j < pow(2, i); j++){
                auto lastbit = bits[lastpos-j];
                bits.push_back(lastbit.flip(i));
            }
        }
        for (auto i : bits)
            res.push_back(i.to_ulong());
        return res;
    }
};