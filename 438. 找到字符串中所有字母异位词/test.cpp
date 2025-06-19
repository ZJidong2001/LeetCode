class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ret;

        int hashp[26] = { 0 };
        for (auto ch : p) ++hashp[ch - 'a'];

        int hashs[26] = { 0 };
        for (int left = 0, right = 0, cnt = 0; right < s.size(); ++right)
        {
            ++hashs[s[right] - 'a'];
            if (hashs[s[right] - 'a'] <= hashp[s[right] - 'a']) ++cnt;

            if (right - left + 1 > p.size())
            {
                if (hashs[s[left] - 'a'] <= hashp[s[left] - 'a']) --cnt;
                --hashs[s[left] - 'a'];
                ++left;
            }

            if (cnt == p.size()) ret.push_back(left);
        }

        return ret;
    }
};