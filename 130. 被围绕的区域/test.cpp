class Solution
{
    typedef pair<int, int> PII;
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };
public:
    void solve(vector<vector<char>>& board)
    {
        queue<PII> q;
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if ((i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1) && board[i][j] == 'O')
                {
                    q.push({ i, j });
                    board[i][j] = 'E';
                    while (!q.empty())
                    {
                        auto [row, col] = q.front();
                        q.pop();
                        for (int k = 0; k < 4; ++k)
                        {
                            int x = row + dr[k], y = col + dc[k];
                            if (x >= 0 && x <= board.size() - 1 && y >= 0 && y <= board[0].size() - 1 && board[x][y] == 'O')
                            {
                                q.push({ x, y });
                                board[x][y] = 'E';
                            }
                        }
                    }
                }

        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (board[i][j] == 'E') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
    }
};