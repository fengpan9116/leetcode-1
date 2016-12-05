// This is the multi char version
std::vector<std::string> explode(const std::string &str, const std::string &delim){
    std::vector<std::string> res;
    std::size_t dlen = delim.length();
    std::size_t i = 0;
    do{
        std::size_t j = i;
        i = str.find(delim, i);
        if (i > j)
            res.push_back(str.substr(j,i-j));
        if (i == std::string::npos) break;
        else i += dlen;
    } while (i < str.length());
    return res;
}

int countOccurrances(const std::string &str, const std::string &delim, bool prefixOnly = false) {
    if (str.empty()) return 0;
    int res = 0;
    std::size_t dlen = delim.length();
    std::size_t i = 0, j;
    while (i < str.length()) {
        j = str.find(delim, i);
        if (j == std::string::npos) break;
        if (prefixOnly) {
            if (i > 0 && j > i+dlen) break;
            else if (i == 0 && j > i) break;
        }
        i = j;
        res++;
        i += dlen;
    }
    return res;
}

class Solution {
public:
    int lengthLongestPath(string input) {
        vector<string> tokens = explode(input, "\n");
        vector<int> lengths;
        int curTabLen = 0, parentTab = -1, maxLength = 0, isFile = 0, spcLen;
        for (auto s : tokens) {
            spcLen = countOccurrances(s, "    ", true);
            if (spcLen) {
                auto correctTabLen = parentTab+1;
                size_t i = 0;
                while (correctTabLen > 0 && spcLen > 0){
                    s.replace(i, 4, "\t");
                    correctTabLen--, spcLen--, i++;
                }
            }
            curTabLen = countOccurrances(s, "\t", true);
            if (curTabLen > parentTab+1) curTabLen = parentTab + 1;
            isFile = countOccurrances(s, ".");
            
            if (parentTab >= curTabLen) {
                // Pop until align
                while (parentTab >= curTabLen){
                    if (lengths.empty()) break;
                    lengths.pop_back();
                    parentTab--;
                }
            }
            if (isFile) {
                int len = s.size()-curTabLen;
                for (auto i : lengths){
                    len += i;
                }
                maxLength = max(len, maxLength);
                continue;
            }
            lengths.emplace_back(s.length()-curTabLen+1);
            parentTab = curTabLen;
        }
        return maxLength;
    }
};