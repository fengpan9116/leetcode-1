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
    string simplifyPath(string path) {
        auto v = tokenize(path, "/");
        if (v.empty()) return "/";
        string res;
        res.reserve(path.size());
        int topop = 0;
        while (!v.empty()) {
            if (v.back() == "..") {
                v.pop_back();
                topop++;
                continue;
            }
            string ins = v.back();
            if (ins == ".") /* ta-da */;
            else if (topop) {
                v.pop_back();
                topop--;
                continue;
            }
            else res.insert(0, "/"+ins);
            v.pop_back();
        }
        if (res.empty()) res = "/";
        else if (res[0] != '/') res.insert(0, "/");
        return res;
    }
};