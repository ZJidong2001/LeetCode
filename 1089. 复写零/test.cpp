class Solution
{
public:
    void duplicateZeros(vector<int>& arr)
    {
        int cur = 0, dst = -1;
        while (cur < arr.size())
        {
            if (arr[cur]) dst += 1;
            else dst += 2;
            if (dst >= arr.size() - 1) break;
            ++cur;
        }

        if (dst == arr.size())
        {
            arr[arr.size() - 1] = 0;
            dst -= 2;
            --cur;
        }

        while (cur >= 0)
        {
            if (arr[cur])
                arr[dst--] = arr[cur--];
            else
            {
                arr[dst--] = 0;
                arr[dst--] = 0;
                --cur;
            }
        }
    }
};