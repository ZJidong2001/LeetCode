class Solution
{
    const string dg = "ACGT";
public:
    int minMutation(string startGene, string endGene, vector<string>& bank)
    {
        int step = 0;

        unordered_set<string> genes(bank.begin(), bank.end());
        if (!genes.count(endGene)) return -1;

        unordered_set<string> visited;

        queue<string> q;
        q.push(startGene);
        visited.insert(startGene);
        while (!q.empty())
        {
            ++step;
            int cnt = q.size();
            while (cnt--)
            {
                string cur_gene = q.front();
                q.pop();
                for (int i = 0; i < 8; ++i)
                {
                    string next_gene = cur_gene;
                    for (int j = 0; j < 4; ++j)
                    {
                        next_gene[i] = dg[j];
                        if (genes.count(next_gene) && !visited.count(next_gene))
                        {
                            if (next_gene == endGene) return step;
                            q.push(next_gene);
                            visited.insert(next_gene);
                        }
                    }
                }
            }
        }

        return -1;
    }
};