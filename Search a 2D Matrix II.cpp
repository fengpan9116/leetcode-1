class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        size_t m = matrix.size(), n = matrix[0].size(), r = 0;
        int start = 0, end = m*n - 1, mid;
        // Search each row
        for (; r < m; r++){
            if (matrix[r][0] > target) break;
            size_t start = 0, end = n-1, mid = 0;
            while (start <= end){
                mid = (end-start)/2 + start;
                if (matrix[r][mid] < target) start = mid + 1;
                else if (matrix[r][mid] > target) end = mid - 1;
                else return true;
            }
        }
        return false;
    }
};