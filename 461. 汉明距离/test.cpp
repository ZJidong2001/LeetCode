class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int ret = 0, tmp = x ^ y;
        while (tmp)
        {
            tmp &= tmp - 1;
            ++ret;
        }
        return ret;
    }
};