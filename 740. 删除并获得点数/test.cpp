class Solution
{
public:
    int deleteAndEarn(vector<int>& nums)
    {
        const int size = 10001;

        vector<int> arr(size);
        for (auto num : nums) arr[num] += num;

        vector<int> dp_selected(size);
        vector<int> dp_no_selected(size);
        for (int i = 1; i < size; ++i)
        {
            dp_selected[i] = dp_no_selected[i - 1] + arr[i];
            dp_no_selected[i] = max(dp_selected[i - 1], dp_no_selected[i - 1]);
        }

        return max(dp_selected.back(), dp_no_selected.back());
    }
};