class Solution
{
public:
    string countAndSay(int n)
    {
        string ret = "1";
        for (int i = 2; i <= n; ++i)
        {
            string tmp;
            for (int left = 0, right = 0; right < ret.size(); )
            {
                while (right < ret.size() && ret[left] == ret[right]) right++;
                tmp += to_string(right - left) + ret[left];
                left = right;
            }
            ret = tmp;
        }
        return ret;
    }
};