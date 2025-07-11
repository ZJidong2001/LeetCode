class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> hash;
        for (auto& str : strs)
        {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            hash[tmp].push_back(str);
        }

        vector<vector<string>> ret;
        for (auto& [key, value] : hash)
            ret.push_back(value);

        return ret;
    }
};