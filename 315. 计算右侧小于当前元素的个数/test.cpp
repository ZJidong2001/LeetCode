class Solution
{
    vector<int> index;
    vector<int> tmpnums;
    vector<int> tmpindex;
public:
    void mergeCount(vector<int>& nums, vector<int>& counts, int begin, int end)
    {
        if (begin >= end) return;

        int mid = (begin + end) >> 1;
        mergeCount(nums, counts, begin, mid);
        mergeCount(nums, counts, mid + 1, end);

        int end1 = begin, end2 = mid + 1, i = begin;
        while (end1 <= mid && end2 <= end)
        {
            if (nums[end1] <= nums[end2])
            {
                tmpnums[i] = nums[end2];
                tmpindex[i++] = index[end2++];
            }
            else
            {
                counts[index[end1]] += end - end2 + 1;
                tmpnums[i] = nums[end1];
                tmpindex[i++] = index[end1++];
            }
        }
        while (end1 <= mid)
        {
            tmpnums[i] = nums[end1];
            tmpindex[i++] = index[end1++];
        }
        while (end2 <= end)
        {
            tmpnums[i] = nums[end2];
            tmpindex[i++] = index[end2++];
        }

        for (int j = begin; j <= end; ++j)
        {
            nums[j] = tmpnums[j];
            index[j] = tmpindex[j];
        }
    }

    vector<int> countSmaller(vector<int>& nums)
    {
        vector<int> counts(nums.size());

        index.resize(nums.size());
        for (int i = 0; i < index.size(); ++i) index[i] = i;

        tmpnums.resize(nums.size());
        tmpindex.resize(index.size());

        mergeCount(nums, counts, 0, nums.size() - 1);

        return counts;
    }
};