class Solution
{
    vector<vector<int>> ret;
    vector<int> path;
    bool check[6];
public:
    void dfs(vector<int>& nums)
    {
        if (path.size() == nums.size())
        {
            ret.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (!check[i])
            {
                path.push_back(nums[i]);
                check[i] = true;
                dfs(nums);
                path.pop_back();
                check[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        dfs(nums);
        return ret;
    }
};