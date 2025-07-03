class Solution
{
public:
    int findMaxLength(vector<int>& nums)
    {
        int len = 0;
        unordered_map<int, int> hash;
        hash[0] = -1;
        for (int i = 0, sum = 0; i < nums.size(); ++i)
        {
            sum += nums[i] == 1 ? 1 : -1;
            if (hash.count(sum)) len = max(i - hash[sum], len);
            else hash[sum] = i;
        }
        return len;
    }
};