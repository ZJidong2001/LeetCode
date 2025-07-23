class MedianFinder
{
    priority_queue<int, vector<int>, less<int>> small_heap;
    priority_queue<int, vector<int>, greater<int>> big_heap;
public:
    MedianFinder() {}

    void addNum(int num)
    {
        if (small_heap.empty() || num <= small_heap.top())
        {
            small_heap.push(num);
            if (small_heap.size() > big_heap.size() + 1)
            {
                big_heap.push(small_heap.top());
                small_heap.pop();
            }
        }
        else
        {
            big_heap.push(num);
            if (big_heap.size() > small_heap.size())
            {
                small_heap.push(big_heap.top());
                big_heap.pop();
            }
        }
    }

    double findMedian()
    {
        if (small_heap.size() == big_heap.size()) return (small_heap.top() + big_heap.top()) / 2.0;
        else return small_heap.top();
    }
};