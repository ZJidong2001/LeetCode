class Solution
{
public:
    int triangleNumber(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        int ret = 0;
        for (int k = nums.size() - 1; k >= 2; --k)
        {
            int left = 0, right = k - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] <= nums[k]) ++left;
                else
                {
                    ret += right - left;
                    --right;
                }
            }
        }
        return ret;
    }
};