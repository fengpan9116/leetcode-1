class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        unsigned xxx = 1;
        unsigned char i = 0, j = 0;
        while (x/xxx >= 10) xxx *= 10;
        while (x > 0){
            i = x/xxx;
            j = x % 10;
            if (i != j) return false;
            x = (x % xxx) / 10;
            xxx /= 100;
        }
        return true;
    }
};