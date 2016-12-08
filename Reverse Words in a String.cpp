// This is a wrapper to std::strtok. Warning: different stuff!
std::vector<std::string> tokenize(const std::string &str, char const* delim){
    std::vector<std::string> res;
    char* cstr = new char[str.size()+1];
    std::strcpy(cstr, str.c_str());
    char* p = std::strtok(cstr, delim);
    while (p){
        res.push_back(p);
        p = std::strtok(NULL, delim);
    }
    delete cstr;
    return res;
}

class Solution {
public:
    void reverseWords(string &s) {
        vector<string> v = tokenize(s, " ");
        if (v.empty()) {
            s = ""; // What the hell leetcode
            return;
        }
        string res;
        for (size_t i = v.size()-1; i > 0; i--)
            res += v[i] + " ";
        res += v[0];
        s = res;
    }
};