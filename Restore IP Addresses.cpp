class Solution {
public:
    bool isValid(const string& s){
        if (s.empty() || s.size() > 3) return false;
        if (s[0] == '0' && s.size() > 1) return false;
        return stoi(s) >= 0 && stoi(s) <= 255;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        auto size = s.size();
        string ichi, ni, san, shi;
        for (size_t i = 1; i < 4 && i < size; i++){
            ichi = s.substr(0, i);
            if (isValid(ichi)){
                for (size_t j = 1; j < 4 && i+j < size; j++){
                    ni = s.substr(i, j);
                    if (isValid(ni)){
                        for (size_t k = 1; k < 4 && i+j+k < size; k++){
                            san = s.substr(i+j, k);
                            shi = s.substr(i+j+k);
                            if (isValid(san) && isValid(shi))
                                res.push_back(ichi + "." + ni + "." + san + "." + shi);
                        }
                    }
                }
            }
        }
    return res;
    }
};