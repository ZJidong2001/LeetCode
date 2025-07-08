class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        int i = 0, left = -1, right = nums.size();
        while (i < right)
        {
            if (nums[i] < 1) swap(nums[++left], nums[i++]);
            else if (nums[i] > 1) swap(nums[--right], nums[i]);
            else ++i;
        }
    }
};