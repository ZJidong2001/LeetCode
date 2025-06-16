class Solution
{
public:
    int longestOnes(vector<int>& nums, int k)
    {
        int zero = 0, ret = 0;
        for (int left = 0, right = 0; right < nums.size(); ++right)
        {
            if (nums[right] == 0) ++zero;
            while (zero > k)
                if (nums[left++] == 0) --zero;
            ret = max(right - left + 1, ret);
        }
        return ret;
    }
};