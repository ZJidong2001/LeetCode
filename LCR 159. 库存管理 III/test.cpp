class Solution
{
public:
    void quickSelect(vector<int>& stock, int cnt, int begin, int end)
    {
        if (begin >= end) return;

        int key = stock[begin + (rand() % (end - begin + 1))];
        int i = begin, left = begin - 1, right = end + 1;
        while (i < right)
        {
            if (stock[i] < key) swap(stock[++left], stock[i++]);
            else if (stock[i] > key) swap(stock[--right], stock[i]);
            else ++i;
        }
        if (left - begin + 1 > cnt) quickSelect(stock, cnt, begin, left);
        else if (right - begin >= cnt) return;
        else quickSelect(stock, cnt - (right - begin), right, end);
    }

    vector<int> inventoryManagement(vector<int>& stock, int cnt)
    {
        srand((unsigned int)time(nullptr));
        quickSelect(stock, cnt, 0, stock.size() - 1);
        return vector<int>(stock.begin(), stock.begin() + cnt);
    }
};