class Solution
{
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int> ret;

        unordered_map<string, int> hashwords;
        for (auto& word : words) ++hashwords[word];

        for (int i = 0; i < words[0].size(); ++i)
        {
            unordered_map<string, int> hashs;
            for (int left = i, right = i, cnt = 0; right + words[0].size() <= s.size(); right += words[0].size())
            {
                ++hashs[s.substr(right, words[0].size())];
                if (hashwords.count(s.substr(right, words[0].size())) && hashs[s.substr(right, words[0].size())] <= hashwords[s.substr(right, words[0].size())]) ++cnt;

                if (right - left + 1 > words.size() * words[0].size())
                {
                    if (hashwords.count(s.substr(left, words[0].size())) && hashs[s.substr(left, words[0].size())] <= hashwords[s.substr(left, words[0].size())]) --cnt;
                    --hashs[s.substr(left, words[0].size())];
                    left += words[0].size();
                }

                if (cnt == words.size()) ret.push_back(left);
            }
        }

        return ret;
    }
};