class Solution {
public:
    bool isPalindrome(string ss) {
        if (ss.empty()) return true;
        string s;
        for (size_t i = 0; i < ss.size(); i++){
            if (isalpha(ss[i])) s += tolower(ss[i]);
            else if (isdigit(ss[i])) s += ss[i];
        }
        stack<char> cstk;
        for (size_t i = 0; i < s.size()/2; i++)
            cstk.push(s[i]);
        for (size_t i = s.size()&1 ? s.size()/2+1 : s.size()/2; i < s.size(); i++){
            if (s[i] != cstk.top()) return false;
            cstk.pop();
        }
        return cstk.empty();
    }
};