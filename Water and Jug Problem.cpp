class Solution {
public:
    int gcd (int x, int y) {
        return x == 0 ? y : gcd(y%x, x);
    }
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || x + y >= z && z % gcd(x, y) == 0;
    }
};