class Solution
{
public:
    int jewelleryValue(vector<vector<int>>& frame)
    {
        vector<vector<int>> dp(frame.size() + 1, vector<int>(frame[0].size() + 1));
        for (int i = 1; i < dp.size(); ++i)
            for (int j = 1; j < dp[0].size(); ++j)
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + frame[i - 1][j - 1];
        return dp.back().back();
    }
};