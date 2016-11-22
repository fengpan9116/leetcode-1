class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        auto m = grid.size(), n = grid[0].size();
        int res = 0;
        for (size_t r = 0; r < m; r++){
            for (size_t c = 0; c < n; c++){
                if (grid[r][c] == 0) continue;
                int sum = 4;
                // n s e w
                if (r > 0 && grid[r-1][c]) sum--;
                if (r < m-1 && grid[r+1][c]) sum--;
                if (c > 0 && grid[r][c-1]) sum--;
                if (c < n-1 && grid[r][c+1]) sum--;
                res += sum;
            }
        }
        return res;
    }
};