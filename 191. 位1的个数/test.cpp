class Solution
{
public:
    int hammingWeight(int n)
    {
        int ret = 0;
        while (n)
        {
            n &= n - 1;
            ++ret;
        }
        return ret;
    }
};