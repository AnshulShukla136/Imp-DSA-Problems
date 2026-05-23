// TC = O(n)
// SC = O(n)
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        int rot = 0;
        int first = nums[0];
        for (int i = 0; i < n; i++)
        {
            if (rot == 1)
            {
                if (nums[i] > nums[0])
                    return false;
            }
            if (i + 1 < n && nums[i] > nums[i + 1])
            {
                rot++;
            }
            if (rot > 1)
                return false;
        }
        return true;
    }
};