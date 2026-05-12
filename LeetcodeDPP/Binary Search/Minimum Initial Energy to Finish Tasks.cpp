class Solution
{
public:
    bool canComplete(vector<vector<int>> &task, int remain)
    {
        int n = task.size();
        for (int i = 0; i < n; i++)
        {
            int minimum = task[i][1];
            int actual = task[i][0];
            if (remain >= minimum)
            {
                remain -= actual;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    int minimumEffort(vector<vector<int>> &task)
    {
        int l = 1;
        int r = 1e9;
        int ans = -1;

        sort(task.begin(), task.end(), [](auto &a, auto &b) { // most important part we will sort on the basis of difference maximum
                                                              // difference first
            return (a[1] - a[0]) > (b[1] - b[0]);

        });

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (canComplete(tasks, mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};