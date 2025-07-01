class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> lproduct(nums.size()), rproduct(nums.size());
        lproduct.front() = 1;
        rproduct.back() = 1;
        for (int i = 1; i <= nums.size() - 1; ++i) lproduct[i] = lproduct[i - 1] * nums[i - 1];
        for (int i = nums.size() - 2; i >= 0; --i) rproduct[i] = rproduct[i + 1] * nums[i + 1];

        vector<int> answer(nums.size());
        for (int i = 0; i < nums.size(); ++i) answer[i] = lproduct[i] * rproduct[i];

        return answer;
    }
};