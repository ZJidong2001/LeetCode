class Solution
{
public:
    int robRange(vector<int>& nums, int left, int right)
    {
        if (left > right) return 0;
        vector<int> dp_rob(nums.size());
        vector<int> dp_no_rob(nums.size());
        dp_rob[left] = nums[left];
        dp_no_rob[left] = 0;
        for (int i = left + 1; i <= right; ++i)
        {
            dp_rob[i] = dp_no_rob[i - 1] + nums[i];
            dp_no_rob[i] = max(dp_rob[i - 1], dp_no_rob[i - 1]);
        }
        return max(dp_rob[right], dp_no_rob[right]);
    }

    int rob(vector<int>& nums)
    {
        if (nums.size() == 1) return nums[0];
        return max(robRange(nums, 0, nums.size() - 2), robRange(nums, 1, nums.size() - 1));
    }
};