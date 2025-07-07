class Solution
{
public:
    int minNumberOfFrogs(string croakOfFrogs)
    {
        string croak = "croak";
        vector<int> cnt(croak.size());
        unordered_map<char, int> index;
        for (int i = 0; i < croak.size(); ++i) index[croak[i]] = i;

        for (auto ch : croakOfFrogs)
        {
            if (ch == 'c')
            {
                if (cnt[index['k']] > 0) --cnt[index['k']];
                ++cnt[index['c']];
            }
            else
            {
                if (cnt[index[ch] - 1] < 1) return -1;
                --cnt[index[ch] - 1];
                ++cnt[index[ch]];
            }
        }

        for (int i = 0; i < cnt.size() - 1; ++i)
            if (cnt[i] != 0) return -1;

        return cnt[index['k']];
    }
};