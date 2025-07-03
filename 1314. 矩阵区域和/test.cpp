class Solution
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k)
    {
        vector<vector<int>> answer(mat.size(), vector<int>(mat[0].size()));

        vector<vector<int>> dp(mat.size() + 1, vector<int>(mat[0].size() + 1));
        for (int i = 1; i <= mat.size(); ++i)
            for (int j = 1; j <= mat[0].size(); ++j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];

        for (int i = 0; i < answer.size(); ++i)
            for (int j = 0; j < answer[0].size(); ++j)
            {
                int x1 = max(i - k, 0), y1 = max(j - k, 0);
                int x2 = min(i + k, (int)mat.size() - 1), y2 = min(j + k, (int)mat[0].size() - 1);
                answer[i][j] = dp[x2 + 1][y2 + 1] + dp[x1][y1] - dp[x1][y2 + 1] - dp[x2 + 1][y1];
            }

        return answer;
    }
};