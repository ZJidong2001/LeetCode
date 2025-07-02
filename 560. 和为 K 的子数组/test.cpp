class Solution
{
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int ret = 0;
        unordered_map<int, int> hash;
        hash[0] = 1;
        for (int i = 0, sum = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            if (hash.count(sum - k)) ret += hash[sum - k];
            ++hash[sum];
        }
        return ret;
    }
};