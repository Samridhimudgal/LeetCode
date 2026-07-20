class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int total = m * n;
        k %= total;

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Current 1D index
                int curr = i * n + j;

                // New 1D index after shifting
                int next = (curr + k) % total;

                // Convert back to 2D
                int newRow = next / n;
                int newCol = next % n;

                ans[newRow][newCol] = grid[i][j];
            }
        }

        return ans;
    }
};