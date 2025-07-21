class Solution
{
public:
    vector<vector<int>> levelOrder(Node* root)
    {
        if (root == nullptr) return {};

        vector<vector<int>> ret;

        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> tmp;
            int cnt = q.size();
            while (cnt--)
            {
                Node* parent = q.front();
                q.pop();
                tmp.push_back(parent->val);
                for (Node* child : parent->children) q.push(child);
            }
            ret.push_back(tmp);
        }

        return ret;
    }
};