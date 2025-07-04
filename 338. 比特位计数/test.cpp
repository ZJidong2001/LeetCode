class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1);
        for (int i = 1, highBit = 0; i < ans.size(); i++)
        {
            if ((i & (i - 1)) == 0) highBit = i;
            ans[i] = ans[i - highBit] + 1;
        }
        return ans;
    }
};