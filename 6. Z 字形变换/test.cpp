class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1) return s;

        string ret;

        for (int i = 0; i < s.size(); i += (2 * numRows - 2))
            ret += s[i];

        for (int k = 1; k <= numRows - 2; ++k)
            for (int i = k, j = 2 * numRows - 2 - k; i < s.size() || j < s.size(); i += (2 * numRows - 2), j += (2 * numRows - 2))
            {
                if (i < s.size()) ret += s[i];
                if (j < s.size()) ret += s[j];
            }

        for (int i = numRows - 1; i < s.size(); i += (2 * numRows - 2))
            ret += s[i];

        return ret;
    }
};