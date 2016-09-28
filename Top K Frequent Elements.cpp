struct Compare{
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.empty()) return res;
        unordered_map<int, int> num_to_cnt;
        for (auto i : nums) num_to_cnt[i]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for (auto i : num_to_cnt){
            if (pq.size() < k)
				pq.push(i);
			else {
				if (pq.top().second < i.second) {
					pq.pop();
					pq.push(i);
				}
			}
            //if (pq.size() > k) pq.pop();
            //pq.push(i);
        }
        while (!pq.empty()){
            res.emplace_back(pq.top().first);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};