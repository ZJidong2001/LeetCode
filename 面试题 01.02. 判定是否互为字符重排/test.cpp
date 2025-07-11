class Solution
{
public:
    bool CheckPermutation(string s1, string s2)
    {
        if (s1.size() != s2.size()) return false;

        int hash[26] = { 0 };

        for (auto ch : s1)
            ++hash[ch - 'a'];

        for (auto ch : s2)
            if (--hash[ch - 'a'] < 0) return false;

        return true;
    }
};