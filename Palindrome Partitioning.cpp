class Solution {
public:
    vector<vector<string>> partition(string s) {
        input = s;
        curse(0);
        return res;
    }
private:
    bool isPalindrome(const string &s){
        for (int i = 0, j = s.size()-1; i < j; i++, j--)
            if (s[i] != s[j]) return false;
        return true;
    }
    void curse(int offset){
        if (offset >= input.size()){
            res.push_back(rest);
            return;
        } 
        for (int i = offset+1; i <= input.size(); i++){
            auto s = input.substr(offset, i-offset);
            if (isPalindrome(s)){
                rest.push_back(s);
                curse(i);
                rest.pop_back();
            }
        }
    }
    vector<vector<string>> res;
    vector<string> rest;
    string input;
};