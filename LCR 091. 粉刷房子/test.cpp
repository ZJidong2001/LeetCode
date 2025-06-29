class Solution
{
public:
    int minCost(vector<vector<int>>& costs)
    {
        vector<vector<int>> dp(costs.size() + 1, vector<int>(3));
        for (int i = 1; i < dp.size(); ++i)
        {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i - 1][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i - 1][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i - 1][2];
        }
        return min(dp.back()[0], min(dp.back()[1], dp.back()[2]));
    }
};