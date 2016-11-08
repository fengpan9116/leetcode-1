class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        auto m = grid.size(), n = grid[0].size();
        int dyna[m][n];
        dyna[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
            dyna[i][0] = dyna[i-1][0] + grid[i][0];
        for (int i = 1; i < n; i++)
            dyna[0][i] = dyna[0][i-1] + grid[0][i];
        for (int r = 1; r < m; r++)
            for (int c = 1; c < n; c++)
                dyna[r][c] = min(dyna[r-1][c], dyna[r][c-1]) + grid[r][c];
        return dyna[m-1][n-1];
    }
};