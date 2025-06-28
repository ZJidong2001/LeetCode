class Solution
{
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix.size() + 2, INT_MAX));
        for (int& x : dp[0]) x = 0;

        for (int i = 1; i <= matrix.size(); ++i)
            for (int j = 1; j <= matrix.size(); ++j)
                dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i - 1][j + 1])) + matrix[i - 1][j - 1];

        int ret = INT_MAX;
        for (int e : dp.back()) ret = min(e, ret);
        return ret;
    }
};
