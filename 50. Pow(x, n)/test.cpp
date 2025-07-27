class Solution
{
public:
    double _myPow(double x, long long n)
    {
        if (n == 0) return 1;
        double y = _myPow(x, n / 2);
        return n % 2 == 0 ? y * y : y * y * x;
    }

    double myPow(double x, int n)
    {
        return n < 0 ? 1 / _myPow(x, -(long long)n) : _myPow(x, n);
    }
};