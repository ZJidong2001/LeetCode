class Solution
{
public:
    int dfs(TreeNode* root, int preSum)
    {
        preSum = preSum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) return preSum;

        int ret = 0;
        if (root->left) ret += dfs(root->left, preSum);
        if (root->right) ret += dfs(root->right, preSum);
        return ret;
    }

    int sumNumbers(TreeNode* root)
    {
        return dfs(root, 0);
    }
};