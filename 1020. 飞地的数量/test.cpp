class Solution
{
    typedef pair<int, int> PII;
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };
public:
    int numEnclaves(vector<vector<int>>& grid)
    {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        queue<PII> q;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if ((i == 0 || i == grid.size() - 1 || j == 0 || j == grid[0].size() - 1) && grid[i][j] == 1)
                {
                    visited[i][j] = true;
                    q.push({ i, j });
                }

        while (!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k)
            {
                int x = row + dr[k], y = col + dc[k];
                if (x >= 0 && x <= grid.size() - 1 && y >= 0 && y <= grid[0].size() - 1 && grid[x][y] == 1 && !visited[x][y])
                {
                    visited[x][y] = true;
                    q.push({ x, y });
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == 1 && !visited[i][j]) ++cnt;
        return cnt;
    }
};