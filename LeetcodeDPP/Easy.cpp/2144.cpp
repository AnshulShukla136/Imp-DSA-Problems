// TC = O(nlogn)
// SC = O(1)

class Solution
{
public:
    int minimumCost(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int k = 0;
        int ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (k == 2)
            {
                k = 0;
                continue;
            }
            if (k == 0 || k == 1)
            {
                ans += nums[i];
            }
            k++;
        }
        return ans;
    }
};