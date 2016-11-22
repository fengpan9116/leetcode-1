class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (g.empty() || s.empty()) return 0;
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        int satisfied = 0;
        for(size_t i = 0; i < g.size(); i++){
            if (satisfied >= s.size()) break;
            if (s[satisfied] < g[i]) continue;
            satisfied++;
        }
        return satisfied;
    }
};