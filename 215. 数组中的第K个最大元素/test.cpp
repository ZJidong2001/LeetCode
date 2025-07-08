class Solution
{
public:
    int quickSelect(vector<int>& nums, int k, int begin, int end)
    {
        int key = nums[begin + (rand() % (end - begin + 1))];
        int i = begin, left = begin - 1, right = end + 1;
        while (i < right)
        {
            if (nums[i] < key) swap(nums[++left], nums[i++]);
            else if (nums[i] > key) swap(nums[--right], nums[i]);
            else ++i;
        }
        if (end - right + 1 >= k) return quickSelect(nums, k, right, end);
        else if (end - left >= k) return key;
        else return quickSelect(nums, k - (end - left), begin, left);
    }

    int findKthLargest(vector<int>& nums, int k)
    {
        srand((unsigned int)time(nullptr));
        return quickSelect(nums, k, 0, nums.size() - 1);
    }
};