class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (auto c : t){
            if (i >= s.size()) return true;
            if (s[i] == c) i++;
        }
        return i >= s.size();
    }
};