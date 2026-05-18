// this is bdf problem
// TC = O(n)
// SC = O(n)S

class Solution
{
public:
    int minJumps(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(0);
        vis[0] = true;
        int ans = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {

                int i = q.front();
                if (i == n - 1)
                    return ans;
                q.pop();

                if (i - 1 >= 0 && !vis[i - 1])
                {
                    q.push(i - 1);
                    vis[i - 1] = true;
                }
                if (i + 1 < n && !vis[i + 1])
                {
                    q.push(i + 1);
                    vis[i + 1] = true;
                }
                auto &vec = mp[nums[i]];
                for (auto &v : vec)
                {
                    if (!vis[v])
                    {
                        q.push(v);
                        vis[v] = true;
                    }
                }
                mp[nums[i]].clear();
            }
            ans++;
        }
        return -1;
    }
};
