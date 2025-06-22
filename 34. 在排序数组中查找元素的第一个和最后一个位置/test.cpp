class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int begin = -1, end = -1;
        if (nums.size() == 0) return { begin, end };

        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        if (nums[left] == target) begin = left;
        else return { begin, end };

        left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] <= target) left = mid;
            else right = mid - 1;
        }
        end = right;
        return { begin, end };
    }
};