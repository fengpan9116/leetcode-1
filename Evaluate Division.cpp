template <class T, typename U> 
struct keyhash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>()(p.first);
        auto h2 = std::hash<T2>()(p.second);
        return h1 ^ h2;  
    }
};

struct keyequal {
    template <class T1, class T2>
    bool operator()(const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs) const{
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        // Floyd Warshall
        vector<double> res;
        unordered_set<string> vertices;
        unordered_map<pair<string, string>, double, keyhash<string, string>> edges;
        for (size_t i = 0; i < equations.size(); i++){
            auto a = equations[i].first;
            auto b = equations[i].second;
            edges[make_pair(a,b)] = values[i];
            edges[make_pair(b,a)] = 1.0 / values[i];
            vertices.insert(a);
            vertices.insert(b);
        }
        for (auto k : vertices){
            edges[make_pair(k,k)] = 1.0;
            for (auto a : vertices)
                for (auto b : vertices)
                    if (edges.count(make_pair(a,k)) && edges.count(make_pair(k,b)))
                        edges[make_pair(a,b)] = edges[make_pair(a,k)] * edges[make_pair(k,b)];
        }
        for (auto q : queries){
            if (edges.count(q)) res.emplace_back(edges[q]);
            else res.emplace_back(-1.0);
        }
        return res;
    }
};