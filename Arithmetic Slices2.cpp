class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        int total = 0, diff = A[1] - A[0], count = 2;
        for (size_t i = 2; i < A.size(); i++){
            if (A[i] - A[i-1] == diff){
                count++;
                if (i == A.size()-1 && count >= 3)
                    total += (count-1)*(count-2) / 2;
            }
            else {
                diff = A[i] - A[i-1];
                if (count >= 3) total += (count-1)*(count-2) / 2;
                count = 2;
            }
        }
        return total;
    }
};