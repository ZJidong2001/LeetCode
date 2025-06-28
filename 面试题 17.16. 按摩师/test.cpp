class Solution
{
public:
    int massage(vector<int>& nums)
    {
        if (nums.size() == 0) return 0;

        vector<int> dp_selected(nums.size());
        vector<int> dp_not_selected(nums.size());
        dp_selected[0] = nums[0];
        dp_not_selected[0] = 0;

        for (int i = 1; i < nums.size(); ++i)
        {
            dp_selected[i] = dp_not_selected[i - 1] + nums[i];
            dp_not_selected[i] = max(dp_selected[i - 1], dp_not_selected[i - 1]);
        }

        return max(dp_selected.back(), dp_not_selected.back());
    }
};