class Solution
{
public:
    int totalFruit(vector<int>& fruits)
    {
        unordered_map<int, int> hash;

        int ret = 0;
        for (int left = 0, right = 0; right < fruits.size(); ++right)
        {
            ++hash[fruits[right]];
            while (hash.size() > 2)
            {
                --hash[fruits[left]];
                if (hash[fruits[left]] == 0) hash.erase(fruits[left]);
                ++left;
            }
            ret = max(right - left + 1, ret);
        }

        return ret;
    }
};