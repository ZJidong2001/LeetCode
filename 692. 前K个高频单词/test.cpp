class Solution
{
    typedef pair<string, int> PSI;
    struct cmp
    {
        bool operator()(const PSI& x, const PSI& y)
        {
            return (x.second > y.second) || (x.second == y.second && x.first < y.first);
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        vector<string> ret(k);

        unordered_map<string, int> hash;
        for (auto& word : words) ++hash[word];

        priority_queue<PSI, vector<PSI>, cmp> pq;
        for (auto& psi : hash)
        {
            pq.push(psi);
            if (pq.size() > k) pq.pop();
        }

        for (int i = k - 1; i >= 0; --i)
        {
            ret[i] = pq.top().first;
            pq.pop();
        }

        return ret;
    }
};