class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        for (int cur = 0, dst = -1; cur < nums.size(); ++cur)
            if (nums[cur]) swap(nums[cur], nums[++dst]);
    }
};