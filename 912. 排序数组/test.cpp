class Solution
{
public:
    void quickSort(vector<int>& nums, int begin, int end)
    {
        if (begin >= end) return;

        int key = nums[begin + (rand() % (end - begin + 1))];
        int i = begin, left = begin - 1, right = end + 1;
        while (i < right)
        {
            if (nums[i] < key) swap(nums[++left], nums[i++]);
            else if (nums[i] > key) swap(nums[--right], nums[i]);
            else ++i;
        }
        quickSort(nums, begin, left);
        quickSort(nums, right, end);
    }

    vector<int> sortArray(vector<int>& nums)
    {
        srand((unsigned int)time(nullptr));
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};