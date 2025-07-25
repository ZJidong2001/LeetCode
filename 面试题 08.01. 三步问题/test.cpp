class Solution
{
public:
    int waysToStep(int n)
    {
        if (n == 1 || n == 2) return n;

        const int MOD = 1e9 + 7;
        vector<int> dp(n + 1);
        dp[1] = 1, dp[2] = 2, dp[3] = 4;
        for (int i = 4; i <= n; ++i)
            dp[i] = ((dp[i - 1] + dp[i - 2]) % 1000000007 + dp[i - 3]) % 1000000007;

        return dp[n];
    }
};