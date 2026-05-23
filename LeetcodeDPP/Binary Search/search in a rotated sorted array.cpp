// TC = O(logn)
// SC = O(1)
// Good problem of binary search
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int s = 0;
        int e = nums.size() - 1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (target == nums[mid])
            {
                return mid;
            }
            if (nums[s] <= nums[mid])
            {
                if (nums[s] <= target && target <= nums[mid])
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
            else
            {
                if (target >= nums[mid] && nums[e] >= target)
                {
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
        }
        return -1;
    }
};