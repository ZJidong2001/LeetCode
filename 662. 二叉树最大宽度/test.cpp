class Solution
{
public:
    int widthOfBinaryTree(TreeNode* root)
    {
        unsigned int ret = 0;

        queue<pair<TreeNode*, unsigned int>> q;
        q.push({ root,1 });
        while (!q.empty())
        {
            ret = max(q.back().second - q.front().second + 1, ret);
            int cnt = q.size();
            while (cnt--)
            {
                pair<TreeNode*, unsigned int> parent = q.front();
                q.pop();
                if (parent.first->left) q.push({ parent.first->left,parent.second * 2 });
                if (parent.first->right) q.push({ parent.first->right,parent.second * 2 + 1 });
            }
        }

        return ret;
    }
};