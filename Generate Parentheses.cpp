class Solution {
public:
    vector<string> generateParenthesis(int n) {
        curse("", n, n);
        return res;
    }
private:
    void curse(string prev, unsigned lbra, unsigned rbra){
        if (lbra == 0 && rbra == 0){
            res.emplace_back(prev);
            return;
        }
        if (lbra > 0)
            curse(prev+'(', lbra-1, rbra);
        if (lbra < rbra)
            curse(prev+')', lbra, rbra-1);
    }
    vector<string> res;
};