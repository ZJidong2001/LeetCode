class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int sum = 0, len = INT_MAX;
        for (int left = 0, right = 0; right < nums.size(); ++right)
        {
            sum += nums[right];
            while (sum >= target)
            {
                len = min(right - left + 1, len);
                sum -= nums[left++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};