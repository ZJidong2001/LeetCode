class KthLargest
{
    priority_queue<int, vector<int>, greater<int>> heap;
    int _k;
public:
    KthLargest(int k, vector<int>& nums) :_k(k)
    {
        for (auto num : nums)
        {
            heap.push(num);
            if (heap.size() > _k) heap.pop();
        }
    }

    int add(int val)
    {
        heap.push(val);
        if (heap.size() > _k) heap.pop();
        return heap.top();
    }
};