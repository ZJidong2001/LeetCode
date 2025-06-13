class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int left = 0, right = height.size() - 1, max_capcity = INT_MIN;
        while (left < right)
        {
            max_capcity = max(min(height[left], height[right]) * (right - left), max_capcity);
            if (height[left] < height[right]) ++left;
            else --right;
        }
        return max_capcity;
    }
};