class Solution
{
public:
    string removeDuplicates(string s)
    {
        string ret;
        for (auto ch : s)
            if (!ret.empty() && ch == ret.back()) ret.pop_back();
            else ret += ch;
        return ret;
    }
};