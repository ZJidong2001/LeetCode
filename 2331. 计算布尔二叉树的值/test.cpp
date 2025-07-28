class Solution
{
public:
    bool evaluateTree(TreeNode* root)
    {
        if (root->left == nullptr) return root->val == 0 ? false : true;
        else return root->val == 2 ? evaluateTree(root->left) || evaluateTree(root->right) : evaluateTree(root->left) && evaluateTree(root->right);
    }
};