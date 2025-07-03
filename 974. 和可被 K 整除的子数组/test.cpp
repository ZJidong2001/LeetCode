class Solution
{
public:
    int subarraysDivByK(vector<int>& nums, int k)
    {
        int ret = 0;
        unordered_map<int, int> hash;
        hash[0] = 1;

        int sum = 0;
        for (auto num : nums)
        {
            sum += num;
            if (hash.count((sum % k + k) % k)) ret += hash[(sum % k + k) % k];
            ++hash[(sum % k + k) % k];
        }

        return ret;
    }
};