class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        vector<vector<int>> dp(dungeon.size() + 1, vector<int>(dungeon[0].size() + 1, INT_MAX));
        dp[dungeon.size() - 1].back() = 1;

        for (int i = dungeon.size() - 1; i >= 0; --i)
            for (int j = dungeon[0].size() - 1; j >= 0; --j)
                dp[i][j] = max(1, min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j]);

        return dp[0][0];
    }
};