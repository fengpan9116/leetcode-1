class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        char* c = new char[s.size()+1];
        strcpy(c, s.c_str());
        char* p = strtok(c, " ");
        while (p) {
            res++;
            p = strtok(NULL, " ");
        }
        return res;
    }
};