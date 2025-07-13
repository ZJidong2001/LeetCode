class Solution
{
public:
    string multiply(string num1, string num2)
    {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        vector<int> tmp(num1.size() + num2.size() - 1);
        for (int i = 0; i < num1.size(); ++i)
            for (int j = 0; j < num2.size(); ++j)
                tmp[i + j] += (num1[i] - '0') * (num2[j] - '0');

        string ret;
        int cur = 0, sum = 0;
        while (cur < tmp.size() || sum)
        {
            if (cur < tmp.size()) sum += tmp[cur++];
            ret += sum % 10 + '0';
            sum /= 10;
        }
        while (ret.size() > 1 && ret.back() == '0') ret.pop_back();

        reverse(ret.begin(), ret.end());

        return ret;
    }
};