// This is the single char version
vector<string> explode(const string &str, char delim){
    string temp;
    vector<string> res;
    for (size_t i = 0; i < str.size(); i++){
        if (str[i] == delim){
            if (!temp.empty()) res.push_back(temp);
            temp.clear();
        }
        else if (i == str.size()-1){
            temp += str[i];
            res.push_back(temp);
        }
        else temp += str[i];
    }
    return res;
}

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1 = explode(version1, '.');
        vector<string> v2 = explode(version2, '.');
        int i = 0;
        while (1){
            if (i >= v1.size() || i >= v2.size()){
                if (v1.size() < v2.size()){
                    for (; i < v2.size(); i++)
                        if (stoi(v2[i])) return -1;
                    return 0;
                }
                else if (v1.size() > v2.size()){
                    for (; i < v1.size(); i++)
                        if (stoi(v1[i])) return 1;
                    return 0;
                }
                else return 0;
            }
            if (stoi(v1[i]) > stoi(v2[i])) return 1;
            else if (stoi(v1[i]) < stoi(v2[i])) return -1;
            i++;
        }
        return 0;
    }
};