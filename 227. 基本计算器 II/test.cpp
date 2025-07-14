class Solution
{
public:
    int calculate(string s)
    {
        vector<int> opd;
        char opr = '+';

        int i = 0;
        while (i < s.size())
        {
            if (s[i] == ' ') ++i;
            else if (s[i] >= '0' && s[i] <= '9')
            {
                int tmp = 0;
                while (i < s.size() && s[i] >= '0' && s[i] <= '9') tmp = tmp * 10 + (s[i++] - '0');

                if (opr == '+') opd.push_back(tmp);
                else if (opr == '-') opd.push_back(-tmp);
                else if (opr == '*') opd.back() *= tmp;
                else if (opr == '/') opd.back() /= tmp;
            }
            else opr = s[i++];
        }

        int ret = 0;
        for (auto e : opd) ret += e;

        return ret;
    }
};