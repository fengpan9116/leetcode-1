class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        unsigned char shifted = 0;
        for (; m != n; shifted++){
            m >>= 1;
            n >>= 1;
        }
        return m << shifted;
    }
};