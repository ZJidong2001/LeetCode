class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> ret;

        vector<vector<int>> edges(numCourses);
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
            ret.push_back(course);
            for (auto edge : edges[course])
            {
                --ins[edge];
                if (ins[edge] == 0) q.push(edge);
            }
        }

        if (ret.size() != numCourses) return {};
        else return ret;
    }
};