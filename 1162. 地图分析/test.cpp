class Solution
{
    typedef pair<int, int> PII;
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };
public:
    int maxDistance(vector<vector<int>>& grid)
    {
        vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), -1));

        queue<PII> q;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == 1)
                {
                    dist[i][j] = 0;
                    q.push({ i, j });
                }

        int ret = -1;
        while (!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k)
            {
                int x = row + dr[k], y = col + dc[k];
                if (x >= 0 && x <= dist.size() - 1 && y >= 0 && y <= dist[0].size() - 1 && dist[x][y] == -1)
                {
                    dist[x][y] = dist[row][col] + 1;
                    q.push({ x, y });
                    ret = max(ret, dist[x][y]);
                }
            }
        }
        return ret;
    }
};