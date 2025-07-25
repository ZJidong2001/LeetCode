class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        int step = 1;

        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) return 0;

        unordered_set<string> visited;

        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        while (!q.empty())
        {
            ++step;
            int cnt = q.size();
            while (cnt--)
            {
                string cur_word = q.front();
                q.pop();
                for (int i = 0; i < cur_word.size(); ++i)
                {
                    string next_word = cur_word;
                    for (char j = 'a'; j <= 'z'; ++j)
                    {
                        next_word[i] = j;
                        if (words.count(next_word) && !visited.count(next_word))
                        {
                            if (next_word == endWord) return step;
                            q.push(next_word);
                            visited.insert(next_word);
                        }
                    }
                }
            }
        }

        return 0;
    }
};