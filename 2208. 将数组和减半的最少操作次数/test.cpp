class Solution
{
public:
    int halveArray(vector<int>& nums)
    {
        int ret = 0;

        double sum = 0;
        priority_queue<double> q;
        for (auto num : nums)
        {
            sum += num;
            q.push(num);
        }

        sum /= 2;
        while (sum > 0)
        {
            double half = q.top() / 2;
            q.pop();
            sum -= half;
            ++ret;
            q.push(half);
        }

        return ret;
    }
};