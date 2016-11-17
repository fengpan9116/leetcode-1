class Solution {
public:
    int longestPalindrome(string s) {
        int chk[128];
        memset(chk, 0, sizeof chk);
        for (auto c : s) chk[c]++;
        int sum = 0, hasOdd = 0;
        for (int i = 65; i < 123; i++){
            if (chk[i] & 1){
                hasOdd = 1;
                sum += chk[i] - 1;
            }
            else sum += chk[i];
        }
        return sum + hasOdd;
    }
};