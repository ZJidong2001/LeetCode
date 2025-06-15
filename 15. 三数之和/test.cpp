class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> ret;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); )
        {
            int left = i + 1, right = nums.size() - 1, target = -nums[i];
            while (left < right)
            {
                if (nums[left] + nums[right] > target) --right;
                else if (nums[left] + nums[right] < target) ++left;
                else
                {
                    ret.push_back({ nums[left],nums[right],nums[i] });
                    ++left, --right;
                    while (left < right && nums[left] == nums[left - 1]) ++left;
                    while (left < right && nums[right] == nums[right + 1]) --right;
                }
            }
            ++i;
            while (i < nums.size() && nums[i] == nums[i - 1]) ++i;
        }

        return ret;
    }
};