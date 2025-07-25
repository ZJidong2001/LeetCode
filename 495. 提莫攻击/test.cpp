class Solution
{
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration)
    {
        int ret = 0;
        for (int i = 1; i < timeSeries.size(); ++i)
        {
            if (timeSeries[i] - timeSeries[i - 1] >= duration) ret += duration;
            else ret += (timeSeries[i] - timeSeries[i - 1]);
        }
        return ret + duration;
    }
};