class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string strmap[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        res.emplace_back("");
        int digit;
        for (auto c : digits) {
            digit = c - '2';
            size_t prevsize = res.size();
            for (int j = 0; j < prevsize; ++j) {
                for (int i = 0; i < strmap[digit].size(); ++i) {
                    if (i == strmap[digit].size()-1){
                        res[j] += strmap[digit][i];
                    } else res.emplace_back(res[j]+strmap[digit][i]);
                }
            }
        }
        return res;
    }
};