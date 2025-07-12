class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string ret = strs[0];
        for (int i = 1; i < strs.size(); ++i)
            for (int j = 0; j < ret.size(); ++j)
                if (ret[j] != strs[i][j]) ret = ret.substr(0, j);
        return ret;
    }
};