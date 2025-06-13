class Solution
{
public:
    int bitSquareSum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        int slow = n;
        int fast = bitSquareSum(n);

        while (slow != fast)
        {
            slow = bitSquareSum(slow);
            fast = bitSquareSum(bitSquareSum(fast));
        }

        return slow == 1;
    }
};