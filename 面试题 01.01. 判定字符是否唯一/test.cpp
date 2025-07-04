class Solution
{
public:
    bool isUnique(string astr)
    {
        if (astr.size() > 26) return false;

        int bitMap = 0;
        for (char ch : astr)
        {
            if (bitMap >> (ch - 'a') & 1) return false;
            bitMap |= 1 << (ch - 'a');
        }
        return true;
    }
};