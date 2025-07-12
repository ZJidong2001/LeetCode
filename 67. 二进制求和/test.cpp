class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ret;
        int cura = a.size() - 1, curb = b.size() - 1, sum = 0;
        while (cura >= 0 || curb >= 0 || sum)
        {
            if (cura >= 0) sum += a[cura--] - '0';
            if (curb >= 0) sum += b[curb--] - '0';
            ret += sum % 2 + '0';
            sum /= 2;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};