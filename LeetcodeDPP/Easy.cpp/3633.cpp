// TC = O(n^2);
// CS = O(1)
class Solution
{
public:
    int earliestFinishTime(vector<int> &landStartTime,
                           vector<int> &landDuration,
                           vector<int> &waterStartTime,
                           vector<int> &waterDuration)
    {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        int ans = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            int finishLand = landStartTime[i] + landDuration[i];

            for (int j = 0; j < m; j++)
            {
                ans = min(ans,
                          max(finishLand, waterStartTime[j]) +
                              waterDuration[j]);
            }
        }

        for (int i = 0; i < m; i++)
        {
            int finishWater = waterStartTime[i] + waterDuration[i];

            for (int j = 0; j < n; j++)
            {
                ans = min(ans,
                          max(finishWater, landStartTime[j]) +
                              landDuration[j]);
            }
        }

        return ans;
    }
};