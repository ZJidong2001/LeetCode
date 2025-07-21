class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        if (root == nullptr) return {};

        vector<vector<int>> ret;

        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            ++level;
            vector<int> tmp;
            int cnt = q.size();
            while (cnt--)
            {
                TreeNode* parent = q.front();
                q.pop();
                tmp.push_back(parent->val);
                if (parent->left) q.push(parent->left);
                if (parent->right) q.push(parent->right);
            }
            if (level % 2 == 0) reverse(tmp.begin(), tmp.end());
            ret.push_back(tmp);
        }

        return ret;
    }
};