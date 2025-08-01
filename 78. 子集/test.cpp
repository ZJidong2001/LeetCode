class Solution
{
    vector<vector<int>> ret;
    vector<int> path;
public:
    void dfs(vector<int>& nums, int pos)
    {
        ret.push_back(path);
        for (int i = pos; i < nums.size(); ++i)
        {
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        dfs(nums, 0);
        return ret;
    }
};