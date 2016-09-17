class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> char_to_cnt;
        for (auto c : s)
            char_to_cnt[c]++;
        for (int i = 0; i < s.length(); i++)
            if (char_to_cnt[s[i]] == 1)
                return i;
        return -1;
    }
};