class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> rest;
        unordered_set<string> seqs;
        string se;
        for (int i = 0; i < s.size(); i++){
            if (i+10 > s.size()) break;
            se = s.substr(i, 10);
            if (seqs.count(se)) rest.insert(se);
            else seqs.insert(se);
        }
        vector<string> res(rest.begin(), rest.end());
        //copy(rest.begin(), rest.end(), back_inserter(res));
        return res;
    }
};