class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        vector<int> chunks;
        int total = 0, diff = A[1] - A[0], count = 2;
        for (size_t i = 2; i < A.size(); i++){
            if (A[i] - A[i-1] == diff){
                count++;
                if (i == A.size()-1 && count >= 3)
                    chunks.emplace_back(count);
            }
            else {
                diff = A[i] - A[i-1];
                if (count >= 3) chunks.emplace_back(count);
                count = 2;
            }
        }
        for (auto n : chunks)
            total += (n-1)*(n-2) / 2;
        return total;
    }
};