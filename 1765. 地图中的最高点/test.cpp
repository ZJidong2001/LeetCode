class Solution
{
    typedef pair<int, int> PII;
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater)
    {
        vector<vector<int>> height(isWater.size(), vector<int>(isWater[0].size(), -1));

        queue<PII> q;
        for (int i = 0; i < isWater.size(); ++i)
            for (int j = 0; j < isWater[0].size(); ++j)
                if (isWater[i][j] == 1)
                {
                    height[i][j] = 0;
                    q.push({ i, j });
                }

        while (!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k)
            {
                int x = row + dr[k], y = col + dc[k];
                if (x >= 0 && x <= height.size() - 1 && y >= 0 && y <= height[0].size() - 1 && height[x][y] == -1)
                {
                    height[x][y] = height[row][col] + 1;
                    q.push({ x, y });
                }
            }
        }

        return height;
    }
};