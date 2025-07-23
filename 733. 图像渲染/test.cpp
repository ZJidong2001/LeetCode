class Solution
{
    typedef pair<int, int> PII;
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        if (image[sr][sc] == color) return image;

        int origin_color = image[sr][sc];

        queue<PII> q;
        q.push({ sr,sc });
        while (!q.empty())
        {
            auto& [row, col] = q.front();
            q.pop();
            image[row][col] = color;
            for (int i = 0; i < 4; ++i)
            {
                int x = row + dr[i], y = col + dc[i];
                if (x >= 0 && x <= image.size() - 1 && y >= 0 && y <= image[0].size() - 1 && image[x][y] == origin_color) q.push({ x,y });
            }
        }

        return image;
    }
};