class Solution
{
public:
    int numDecodings(string s)
    {
        vector<int> dp(s.size() + 1);
        dp[0] = 1;
        dp[1] = s[0] != '0';

        for (int i = 2; i < dp.size(); ++i)
        {
            if (s[i - 1] != '0') dp[i] += dp[i - 1];
            if (10 <= (s[i - 2] - '0') * 10 + (s[i - 1] - '0') && (s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26) dp[i] += dp[i - 2];
        }

        return dp.back();
    }
};