class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> nums;
        stack<string> strs;
        strs.push("");

        int i = 0;
        while (i < s.size())
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                int num = 0;
                while (s[i] >= '0' && s[i] <= '9') num = num * 10 + (s[i++] - '0');
                nums.push(num);
            }
            else if (s[i] == '[')
            {
                strs.push("");
                ++i;
            }
            else if (s[i] == ']')
            {
                int num = nums.top();
                nums.pop();
                string str = strs.top();
                strs.pop();
                while (num--) strs.top() += str;
                ++i;
            }
            else
            {
                strs.top() += s[i++];
            }
        }
        return strs.top();
    }
};