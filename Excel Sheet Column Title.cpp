class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n > 0){
            char c = (char)(--n % 26 + 'A');
            res += c;
            n /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
private:
    char nToAlpha(int n){
        return 'A' - 1 + n;
    }
};