// No memoisation we have made 1d visited array just like dfs
// TC = O(n)
// SC = O(n)

class Solution
{
public:
    bool solve(vector<int> &nums, int i, vector<bool> &vis)
    {
        if (i < 0 || i >= nums.size())
            return false;

        if (nums[i] == 0)
            return true;
        if (vis[i])
            return false;
        vis[i] = true;
        bool first = solve(nums, i + nums[i], vis);
        bool second = solve(nums, i - nums[i], vis);

        return first || second;
    }
    bool canReach(vector<int> &nums, int start)
    {
        vector<bool> vis(nums.size(), false);
        return solve(nums, start, vis);
    }
};