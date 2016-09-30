class Solution {
public:
    int minDistance(string word1, string word2) {
        a = word1;
        b = word2;
        dist.assign(a.size(), vector<int>(b.size(), -1));
        return curse(a.size()-1, b.size()-1);
    }
private:
    int curse(int ia, int ib){
        if (ia < 0) return ++ib;
        else if (ib < 0) return ++ia;
        if (dist[ia][ib] == -1){
            if (a[ia] == b[ib])
                dist[ia][ib] = curse(ia-1, ib-1);
            else{
                int sub = curse(ia-1, ib-1);
                int add = curse(ia-1, ib);
                int del = curse(ia, ib-1);
                dist[ia][ib] = min({add, sub, del}) + 1;
            }
        }
        return dist[ia][ib];
    }
    string a, b;
    vector<vector<int>> dist;
};