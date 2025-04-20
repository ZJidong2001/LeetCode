/*
哈希表
使用一个哈希表num_index_map来存储每个元素及其对应的索引
遍历数组nums，对于当前元素nums[i]，我们首先判断target-nums[i]是否在哈希表num_index_map中，如果在num_index_map中，说明target值已经找到，返回target-nums[i]的索引和i即可
*/

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		unordered_map<int, int> num_index_map;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (num_index_map.find(target - nums[i]) != num_index_map.end())
				return {num_index_map[target - nums[i]], i};
			num_index_map[nums[i]] = i;
		}
		return {};
	}
};