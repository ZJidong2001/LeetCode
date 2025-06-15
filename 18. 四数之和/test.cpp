class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> ret;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); )
        {
            for (int j = i + 1; j < nums.size(); )
            {
                int left = j + 1, right = nums.size() - 1;
                long long aim = (long long)target - nums[i] - nums[j];
                while (left < right)
                {
                    if (nums[left] + nums[right] > aim) --right;
                    else if (nums[left] + nums[right] < aim) ++left;
                    else
                    {
                        ret.push_back({ nums[i],nums[j],nums[left++],nums[right--] });
                        while (left < right && nums[left] == nums[left - 1]) ++left;
                        while (left < right && nums[right] == nums[right + 1]) --right;
                    }
                }
                ++j;
                while (j < nums.size() && nums[j] == nums[j - 1]) ++j;
            }
            ++i;
            while (i < nums.size() && nums[i] == nums[i - 1]) ++i;
        }

        return ret;
    }
};