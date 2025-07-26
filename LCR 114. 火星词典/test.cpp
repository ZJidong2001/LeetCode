class Solution
{
public:
    bool addEdgeAndIn(const string& s1, const string& s2, unordered_map<char, vector<char>>& edges, unordered_map<char, int>& ins)
    {
        int i = 0;
        while (i < min(s1.size(), s2.size()))
        {
            if (s1[i] != s2[i])
            {
                edges[s1[i]].push_back(s2[i]);
                ++ins[s2[i]];
                return true;
            }
            ++i;
        }
        return i == s1.size() && i <= s2.size();
    }

    string alienOrder(vector<string>& words)
    {
        string ret;

        unordered_map<char, vector<char>> edges;
        unordered_map<char, int> ins;
        for (auto& word : words)
            for (auto ch : word)
                ins[ch] = 0;
        for (int i = 0; i < words.size(); ++i)
            for (int j = i + 1; j < words.size(); ++j)
                if (!addEdgeAndIn(words[i], words[j], edges, ins)) return "";

        queue<char> q;
        for (auto in : ins)
            if (in.second == 0) q.push(in.first);
        while (!q.empty())
        {
            char ch = q.front();
            q.pop();
            ret += ch;
            for (auto edge : edges[ch])
            {
                --ins[edge];
                if (ins[edge] == 0) q.push(edge);
            }
        }

        for (auto in : ins)
            if (in.second != 0) return "";
        return ret;
    }
};