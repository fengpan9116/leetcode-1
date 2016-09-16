class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int N = citations.size(), h = 1;
        while (h <= N){
            if (citations[h-1] < h) break;
            h++;
        }
        return h-1;
    }
};