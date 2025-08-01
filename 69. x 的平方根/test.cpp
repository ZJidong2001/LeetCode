class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0) return 0;

        int left = 1, right = x;
        while (left < right)
        {
            long long mid = left + (right - left + 1) / 2;
            if (mid * mid <= x) left = mid;
            else right = mid - 1;
        }
        return left;
    }
};