class Solution
{
    typedef pair<int, int> PII;
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
    {
        int step = 0;
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));

        queue<PII> q;
        q.push({ entrance.front(), entrance.back() });
        visited[entrance.front()][entrance.back()] = true;
        while (!q.empty())
        {
            ++step;
            int cnt = q.size();
            while (cnt--)
            {
                auto [row, col] = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k)
                {
                    int x = row + dr[k], y = col + dc[k];
                    if (x >= 0 && x <= maze.size() - 1 && y >= 0 && y <= maze[0].size() - 1 && maze[x][y] == '.' && !visited[x][y])
                    {
                        if (x == 0 || x == maze.size() - 1 || y == 0 || y == maze[0].size() - 1) return step;
                        q.push({ x, y });
                        visited[x][y] = true;
                    }
                }
            }
        }

        return -1;
    }
};