class Solution
{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        stack<int> st;
        int i = 0;
        for (auto x : pushed)
        {
            st.push(x);
            while (!st.empty() && popped[i] == st.top())
            {
                ++i;
                st.pop();
            }
        }
        return st.empty();
    }
};