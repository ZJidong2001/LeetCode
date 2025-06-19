class Solution
{
public:
    string minWindow(string s, string t)
    {
        int hasht[128] = { 0 };
        int kinds = 0;
        for (auto ch : t)
            if (hasht[ch]++ == 0) ++kinds;

        int begin = -1, len = INT_MAX;
        int hashs[128] = { 0 };
        for (int left = 0, right = 0, cnt = 0; right < s.size(); ++right)
        {
            if (++hashs[s[right]] == hasht[s[right]]) ++cnt;
            while (cnt == kinds)
            {
                if (right - left + 1 < len)
                {
                    len = right - left + 1;
                    begin = left;
                }
                if (hashs[s[left]]-- == hasht[s[left]]) --cnt;
                ++left;
            }
        }

        return begin == -1 ? "" : s.substr(begin, len);
    }
};