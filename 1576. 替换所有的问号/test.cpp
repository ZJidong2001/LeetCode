class Solution
{
public:
    string modifyString(string s)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '?')
            {
                for (char ch = 'a'; ch <= 'c'; ++ch)
                {
                    if ((i == 0 || ch != s[i - 1]) && (i == s.size() - 1 || ch != s[i + 1]))
                    {
                        s[i] = ch;
                        break;
                    }
                }
            }
        }
        return s;
    }
};