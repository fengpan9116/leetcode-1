class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        string line;
        res.push_back(line);
        // Greedily add
        for (int j = 0; j < words.size(); j++){
            auto i = words[j];
            if (res.back().size() + i.size() <= maxWidth)
                res.back() += i;
            // Test next
            if (j < words.size()-1 && res.back().size() + words[j+1].size() + 1 <= maxWidth)
                res.back() += ' ';
            else {
                line.clear();
                res.push_back(line);
            }
        }
        if (res.size() > 1 && res.back().empty()) res.pop_back();
        // Distribute
        for (int j = 0; j < res.size(); j++){
            auto i = res[j].find(' ');
            if (j == res.size()-1 || i == std::string::npos){
                res[j].insert(res[j].size(), maxWidth-res[j].size(), ' ');
                continue;
            }
            while (res[j].size() < maxWidth){
                res[j].insert(i, " ");
                // Skip spaces
                while (i < res[j].size() && res[j][i] == ' ') i++;
                i = res[j].find(' ', i);
                if (i == std::string::npos)
                    i = res[j].find(' ');
            }
        }
        return res;
    }
};