class Solution
{
    long long prev = LLONG_MIN;
public:
    bool isValidBST(TreeNode* root)
    {
        if (root == nullptr) return true;
        if (!isValidBST(root->left)) return false;
        if (prev >= root->val) return false;
        prev = root->val;
        if (!isValidBST(root->right)) return false;
        return true;
    }
};