class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int hash[128] = { 0 };
        int left = 0, right = 0, len = 0;
        while (right < s.size())
        {
            ++hash[s[right]];
            while (hash[s[right]] > 1)
                --hash[s[left++]];
            len = max(len, right - left + 1);
            ++right;
        }
        return len;
    }
};