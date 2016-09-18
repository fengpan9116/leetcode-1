class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (wordDict.count(s) || s.empty()) return true;
        vector<bool> dyna;
        auto size = s.size();
        dyna.insert(dyna.begin(), size, false);
        for (int i = 0; i < size; i++){
            if (i == 0 || dyna[i-1]){
                for (int j = i; j < size; j++)
                    if (!dyna[j] && wordDict.count(s.substr(i, j-i+1))) dyna[j] = true;
            }
            if (dyna[size-1]) return true;
        }
        return dyna[size-1];
    }
};