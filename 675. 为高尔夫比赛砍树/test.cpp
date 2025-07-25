class Solution
{
    typedef pair<int, int> PII;
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };
public:
    int bfs(vector<vector<int>>& forest, int begin_row, int begin_col, int end_row, int end_col)
    {
        if (begin_row == end_row && begin_col == end_col) return 0;

        int step = 0;

        vector<vector<bool>> visited(forest.size(), vector<bool>(forest[0].size(), false));

        queue<PII> q;
        q.push({ begin_row, begin_col });
        visited[begin_row][begin_col] = true;
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
                    if (x >= 0 && x <= forest.size() - 1 && y >= 0 && y <= forest[0].size() - 1 && forest[x][y] && !visited[x][y])
                    {
                        if (x == end_row && y == end_col) return step;
                        q.push({ x, y });
                        visited[x][y] = true;
                    }
                }
            }
        }

        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest)
    {
        int total_step = 0;

        vector<PII> trees;
        for (int i = 0; i < forest.size(); ++i)
            for (int j = 0; j < forest[0].size(); ++j)
                if (forest[i][j] > 1) trees.push_back({ i, j });
        sort(trees.begin(), trees.end(), [&](const PII& tree1, const PII& tree2)
            {
                return forest[tree1.first][tree1.second] < forest[tree2.first][tree2.second];
            });

        int begin_row = 0, begin_col = 0;
        for (auto& [end_row, end_col] : trees)
        {
            int step = bfs(forest, begin_row, begin_col, end_row, end_col);
            if (step == -1) return -1;
            total_step += step;
            begin_row = end_row, begin_col = end_col;
        }

        return total_step;
    }
};