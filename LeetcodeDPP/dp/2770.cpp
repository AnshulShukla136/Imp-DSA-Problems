class Solution
{
public:
    int solve(vector<int> &nums, int target, int i, vector<int> &dp)
    {

        if (i == nums.size() - 1)
            return dp[i] = 0;
        if (dp[i] != -1)
            return dp[i];
        int res = INT_MIN;
        for (int j = i + 1; j < nums.size(); j++)
        { // from current index forward we have choice in which we can go so a for loop
            if (abs(nums[i] - nums[j]) <= target)
            {
                int take = 1 + solve(nums, target, j, dp);
                res = max(res, take);
            }
        }
        return dp[i] = res;
    }
    int maximumJumps(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        int ans = solve(nums, target, 0, dp);
        return ans < 0 ? -1 : ans;
    }
};