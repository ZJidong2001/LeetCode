class Solution
{
    vector<string> ret;
public:
    void dfs(TreeNode* root, string path)
    {
        path += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr)
        {
            ret.push_back(path);
            return;
        }

        path += "->";
        if (root->left) dfs(root->left, path);
        if (root->right) dfs(root->right, path);
    }

    vector<string> binaryTreePaths(TreeNode* root)
    {
        dfs(root, "");
        return ret;
    }
};