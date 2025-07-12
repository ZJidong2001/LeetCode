class Solution
{
public:
    string longestPalindrome(string s)
    {
        int begin = 0, len = 0;

        int left = 0, right = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            left = i - 1, right = i + 1;
            while (left >= 0 && right <= s.size() - 1 && s[left] == s[right])
            {
                --left;
                ++right;
            }
            if (right - left - 1 > len)
            {
                begin = left + 1;
                len = right - left - 1;
            }

            left = i, right = i + 1;
            while (left >= 0 && right <= s.size() - 1 && s[left] == s[right])
            {
                --left;
                ++right;
            }
            if (right - left - 1 > len)
            {
                begin = left + 1;
                len = right - left - 1;
            }
        }

        return s.substr(begin, len);
    }
};