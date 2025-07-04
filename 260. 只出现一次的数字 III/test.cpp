class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        unsigned int tmp = 0;
        for (auto num : nums) tmp ^= num;

        int div = tmp & -tmp, x = 0, y = 0;
        for (auto num : nums)
            if (num & div) x ^= num;
            else y ^= num;

        return { x, y };
    }
};