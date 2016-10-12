class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> rest;
        curse(candidates, rest, 0, target);
        return res;
    }
private:
    vector<vector<int>> res;
    void curse(vector<int>& candidates, vector<int>& rest, unsigned start_idx, int target){
        if (target == 0){
            res.push_back(rest);
            return;
        }
        for (unsigned i = start_idx; i < candidates.size(); i++){
            if (i > start_idx && candidates[i] == candidates[i-1]) continue;
            if (candidates[i] <= target){
                rest.push_back(candidates[i]);
                curse(candidates, rest, i, target-candidates[i]);
                rest.pop_back();
            }
        }
        return;
    }
};