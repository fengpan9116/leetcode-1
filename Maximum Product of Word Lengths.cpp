class Solution {
public:
    int maxProduct(vector<string>& words_) {
        size_t gmax = 0;
        vector<unsigned> words;
        for (auto s : words_){
            unsigned sb = 0;
            for (auto c : s) sb |= 1 << (c-'a');
            words.emplace_back(sb);
        }
        for (size_t i = 0; i < words.size()-1; i++)
            for (size_t j = i+1; j < words.size(); j++)
                if (!(words[i] & words[j]))
                    gmax = max(words_[i].size() * words_[j].size(), gmax);
        return gmax;
    }
private:
    bool testEqual(const string& s1, const string& s2){
        bitset<26> sb1;
        bitset<26> sb2;
        for (auto c : s1) sb1.set(c-'a');
        for (auto c : s2) sb2.set(c-'a');
        return !(sb1 & sb2).count();
    }
};