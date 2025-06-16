class Solution
{
public:
    int minOperations(vector<int>& nums, int x)
    {
        int sum = 0;
        for (int num : nums) sum += num;
        int target = sum - x;
        if (target < 0) return -1;

        int len = INT_MIN;
        for (int left = 0, right = 0, tmp = 0; right < nums.size(); ++right)
        {
            tmp += nums[right];
            while (tmp > target) tmp -= nums[left++];
            if (tmp == target) len = max(right - left + 1, len);
        }

        return len == INT_MIN ? -1 : nums.size() - len;
    }
};