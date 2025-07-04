class Solution
{
public:
    vector<int> missingTwo(vector<int>& nums)
    {
        unsigned int tmp = 0;
        for (int i = 1; i <= nums.size() + 2; ++i) tmp ^= i;
        for (auto num : nums) tmp ^= num;

        int div = tmp & -tmp, x = 0, y = 0;
        for (int i = 1; i <= nums.size() + 2; ++i)
            if (i & div) x ^= i;
            else y ^= i;
        for (auto num : nums)
            if (num & div) x ^= num;
            else y ^= num;

        return { x, y };
    }
};