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
    bool isMatch(string s, string p) {
        size_t si = 0, slen = s.size(), i;
        vector<string> tokens = tokenize(p, "*");
        for (i = 0; i < tokens.size() && si < slen; i++) {
            auto grandtoken = tokens[i];
            auto qpos = grandtoken.find('?'); // in p
            bool hasq = !(qpos == string::npos);
            string token = hasq ? grandtoken.substr(0, qpos) : grandtoken;
            auto matchpos = s.find(token, si);
            if (matchpos == string::npos || 
                i == 0 && p[0] != '*' && matchpos != 0)
                return false;
            si = matchpos + token.size();
            if (hasq) {
                // Match one by one
                while (qpos < grandtoken.size()) {
                    if (si >= slen) goto wow;
                    if (grandtoken[qpos] == '?' || grandtoken[qpos] == s[si]) {
                        si++, qpos++;
                    }
                    else return false;
                }
            }
        }
        wow:
        return i == tokens.size() && (si == slen || !p.empty() && p.back() == '*');
    }
};