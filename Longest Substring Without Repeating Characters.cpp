class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        unordered_map<char, int> char_to_idx;
        int maxLen = 1;
        for (int i = 0, j = 0; j < s.size(); j++){
            if (char_to_idx.count(s[j])) i = max(i, char_to_idx[s[j]]+1);
            char_to_idx[s[j]] = j;
            maxLen = max(maxLen, j-i+1);
        }
        return maxLen;
    }
};