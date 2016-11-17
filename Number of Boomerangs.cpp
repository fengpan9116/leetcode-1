class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        for (auto a : points){
            unordered_map<int, int> dist_cnt;
            for (auto b : points){
                auto x = a.first - b.first;
                auto y = a.second - b.second;
                dist_cnt[pow(x,2)+pow(y,2)]++;
            }
            for (auto it : dist_cnt)
                res += it.second * (it.second-1);
        }
        return res;
    }
};