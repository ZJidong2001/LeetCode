class Solution
{
    int cnt = 0;
    int ret = 0;
public:
    void dfs(TreeNode* root)
    {
        if (root == nullptr || cnt == 0) return;
        dfs(root->left);
        --cnt;
        if (cnt == 0) ret = root->val;
        dfs(root->right);
    }

    int kthSmallest(TreeNode* root, int k)
    {
        cnt = k;
        dfs(root);
        return ret;
    }
};