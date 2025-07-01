class Solution
{
public:
    int pivotIndex(vector<int>& nums)
    {
        vector<int> lsum(nums.size()), rsum(nums.size());
        for (int i = 1; i <= nums.size() - 1; ++i) lsum[i] = lsum[i - 1] + nums[i - 1];
        for (int i = nums.size() - 2; i >= 0; --i) rsum[i] = rsum[i + 1] + nums[i + 1];

        for (int i = 0; i < nums.size(); ++i)
            if (lsum[i] == rsum[i]) return i;

        return -1;
    }
};