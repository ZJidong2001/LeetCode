class Solution
{
public:
    string largestNumber(vector<int>& nums)
    {
        string ret;

        vector<string> numstrs;
        for (auto num : nums) numstrs.push_back(to_string(num));
        sort(numstrs.begin(), numstrs.end(), [](const string& s1, const string& s2)
            {
                return s1 + s2 > s2 + s1;
            });

        for (auto& numstr : numstrs) ret += numstr;

        if (ret[0] == '0') return "0";
        return ret;
    }
};