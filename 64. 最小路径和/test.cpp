class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, INT_MAX));
        dp[0][1] = 0;
        for (int i = 1; i < dp.size(); ++i)
            for (int j = 1; j < dp[0].size(); ++j)
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
        return dp.back().back();
    }
};