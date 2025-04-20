/*
暴力枚举
对于每个元素nums[i]，遍历右侧元素是否存在target-nums[i]
*/

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		for (int i = 0; i < nums.size(); ++i)
			for (int j = i + 1; j < nums.size(); ++j)
				if (nums[i] + nums[j] == target)
					return {i, j};
		return {};
	}
};