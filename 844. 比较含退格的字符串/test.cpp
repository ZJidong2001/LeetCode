class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        string tmps, tmpt;
        for (auto ch : s)
            if (ch != '#') tmps += ch;
            else if (!tmps.empty()) tmps.pop_back();
        for (auto ch : t)
            if (ch != '#') tmpt += ch;
            else if (!tmpt.empty()) tmpt.pop_back();
        return tmps == tmpt;
    }
};