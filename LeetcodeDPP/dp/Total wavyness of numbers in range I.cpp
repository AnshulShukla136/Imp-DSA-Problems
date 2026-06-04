// TC = O(n - m)logm
// SC = logm

class Solution
{
public:
    int countWavy(int n)
    {
        int cnt = 0;

        vector<int> temp;
        while (n > 0)
        {
            temp.push_back(n % 10);
            n = n / 10;
        }
        int sz = temp.size();
        for (int i = 1; i < sz - 1; i++)
        {
            if (temp[i] > temp[i + 1] && temp[i] > temp[i - 1])
            {
                cnt++;
            }
            else if (temp[i] < temp[i + 1] && temp[i] < temp[i - 1])
            {
                cnt++;
            }
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2)
    {
        int cnt = 0;
        for (int i = num1; i <= num2; i++)
        {
            if (i < 100)
                continue;
            cnt += countWavy(i);
        }
        return cnt;
    }
};