class Solution
{
    typedef pair<int, int> PII;
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        vector<vector<int>> ret(mat.size(), vector<int>(mat[0].size(), -1));

        queue<PII> q;
        for (int i = 0; i < mat.size(); ++i)
            for (int j = 0; j < mat[0].size(); ++j)
                if (mat[i][j] == 0)
                {
                    ret[i][j] = 0;
                    q.push({ i, j });
                }

        while (!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k)
            {
                int x = row + dr[k], y = col + dc[k];
                if (x >= 0 && x <= ret.size() - 1 && y >= 0 && y <= ret[0].size() - 1 && ret[x][y] == -1)
                {
                    ret[x][y] = ret[row][col] + 1;
                    q.push({ x, y });
                }
            }
        }

        return ret;
    }
};