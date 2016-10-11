template <typename T>
T linearAccess(vector<vector<T>>& matrix, size_t idx){
    size_t m = matrix.size(), n = matrix[0].size();
    size_t r = idx / n, c = idx % n;
    return matrix[r][c];
}

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        size_t m = matrix.size(), n = matrix[0].size();
        int start = 0, end = m*n - 1, mid;
        while (start <= end){
            mid = (end-start)/2 + start;
            auto val = linearAccess(matrix, mid);
            if (val < target) start = mid + 1;
            else if (val > target) end = mid - 1;
            else return true;
        }
        return false;
    }
};