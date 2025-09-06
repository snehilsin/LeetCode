class Solution {
public:
    int helper(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid){
        if (i == 0 && j == 0) return grid[i][j];
        if (i < 0 || j < 0) return 1e9;
        if (dp[i][j] != -1) return dp[i][j];
        int u = helper(i-1, j, dp, grid);
        int l = helper(i, j-1, dp, grid);
        return dp[i][j] = grid[i][j] + min(l, u);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n-1,m-1,dp, grid);
    }
};