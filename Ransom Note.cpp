class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.empty()) return true;
        if (magazine.empty()) return false;
        unordered_map<char, int> char_to_cnt;
        for (auto c : magazine)
            char_to_cnt[c]++;
        for (auto c : ransomNote){
            if (!char_to_cnt.count(c) || char_to_cnt[c] <= 0) return false;
            else char_to_cnt[c]--;
        }
        return true;
    }
};