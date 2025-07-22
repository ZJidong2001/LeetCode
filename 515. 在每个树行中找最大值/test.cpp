class Solution
{
public:
    vector<int> largestValues(TreeNode* root)
    {
        if (root == nullptr) return {};

        vector<int> ret;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int max_val = INT_MIN;
            int cnt = q.size();
            while (cnt--)
            {
                TreeNode* parent = q.front();
                q.pop();
                max_val = max(parent->val, max_val);
                if (parent->left) q.push(parent->left);
                if (parent->right) q.push(parent->right);
            }
            ret.push_back(max_val);
        }

        return ret;
    }
};