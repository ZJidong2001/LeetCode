class Solution
{
    typedef pair<int, int> PII;
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int max_area = 0;
        queue<PII> q;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == 1)
                {
                    int area = 0;
                    q.push({ i, j });
                    grid[i][j] = 0;
                    while (!q.empty())
                    {
                        ++area;
                        auto [row, col] = q.front();
                        q.pop();
                        for (int k = 0; k < 4; ++k)
                        {
                            int x = row + dr[k], y = col + dc[k];
                            if (x >= 0 && x <= grid.size() - 1 && y >= 0 && y <= grid[0].size() - 1 && grid[x][y] == 1)
                            {
                                q.push({ x, y });
                                grid[x][y] = 0;
                            }
                        }
                    }
                    max_area = max(area, max_area);
                }
        return max_area;
    }
};