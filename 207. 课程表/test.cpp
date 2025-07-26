class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        unordered_map<int, vector<int>> edges;
        vector<int> ins(numCourses);
        for (auto& prerequisite : prerequisites)
        {
            edges[prerequisite.back()].push_back(prerequisite.front());
            ++ins[prerequisite.front()];
        }

        queue<int> q;
        for (int i = 0; i < ins.size(); ++i)
            if (ins[i] == 0) q.push(i);
        while (!q.empty())
        {
            int course = q.front();
            q.pop();
            for (auto edge : edges[course])
            {
                --ins[edge];
                if (ins[edge] == 0) q.push(edge);
            }
        }

        for (auto in : ins)
            if (in != 0) return false;
        return true;
    }
};