class Solution
{
public:
    void move(vector<int>& A, vector<int>& B, vector<int>& C, int n)
    {
        if (n == 1)
        {
            C.push_back(A.back());
            A.pop_back();
            return;
        }
        move(A, C, B, n - 1);
        move(A, B, C, 1);
        move(B, A, C, n - 1);
    }

    void hanota(vector<int>& A, vector<int>& B, vector<int>& C)
    {
        move(A, B, C, A.size());
    }
};