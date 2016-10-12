class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        vector<int> purr;
        for (int i = 1; i <= n; i++) purr.emplace_back(i);
        for (int i = 0; i < n; i++){
            auto cur = range_permutation(purr, k);
            res += to_string(cur);
        }
        return res;
    }
private:
    // Assume v is sorted
    // ceil(k/(n-1)!) % n
    int range_permutation(vector<int>& v, int k){
        int n = v.size();
        int i = n > 1 ? (int)ceil((double)k/(double)factorial((n-1))) % n - 1 : 0;
        if (i < 0) i = n - 1;
        auto ret = v[i];
        v.erase(v.begin()+i);
        return ret;
    }
    int factorial(int n){
        for (int i = n-1; i > 1; i--) n *= i;
        return n;
    }
};