class Solution
{
    vector<int> tmp;
public:
    int mergeCount(vector<int>& record, int begin, int end)
    {
        if (begin >= end) return 0;

        int ret = 0;
        int mid = (begin + end) >> 1;
        ret += mergeCount(record, begin, mid);
        ret += mergeCount(record, mid + 1, end);

        int end1 = begin, end2 = mid + 1, i = begin;
        while (end1 <= mid && end2 <= end)
        {
            if (record[end1] <= record[end2]) tmp[i++] = record[end1++];
            else
            {
                ret += mid - end1 + 1;
                tmp[i++] = record[end2++];
            }
        }
        while (end1 <= mid) tmp[i++] = record[end1++];
        while (end2 <= end) tmp[i++] = record[end2++];

        for (int j = begin; j <= end; ++j) record[j] = tmp[j];

        return ret;
    }

    int reversePairs(vector<int>& record)
    {
        tmp.resize(record.size());
        return mergeCount(record, 0, record.size() - 1);
    }
};