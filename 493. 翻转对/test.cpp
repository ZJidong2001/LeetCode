class Solution
{
    vector<int> tmp;
public:
    int mergeCount(vector<int>& nums, int begin, int end)
    {
        if (begin >= end) return 0;

        int ret = 0;
        int mid = (begin + end) >> 1;
        ret += mergeCount(nums, begin, mid);
        ret += mergeCount(nums, mid + 1, end);

        int cur1 = begin, cur2 = mid + 1;
        while (cur2 <= end)
        {
            while (cur1 <= mid && nums[cur2] >= nums[cur1] / 2.0) ++cur1;
            if (cur1 > mid) break;
            ret += mid - cur1 + 1;
            ++cur2;
        }

        int end1 = begin, end2 = mid + 1, i = begin;
        while (end1 <= mid && end2 <= end)
            tmp[i++] = nums[end1] <= nums[end2] ? nums[end1++] : nums[end2++];
        while (end1 <= mid) tmp[i++] = nums[end1++];
        while (end2 <= end) tmp[i++] = nums[end2++];

        for (int j = begin; j <= end; ++j)
            nums[j] = tmp[j];

        return ret;
    }

    int reversePairs(vector<int>& nums)
    {
        tmp.resize(nums.size());
        return mergeCount(nums, 0, nums.size() - 1);
    }
};