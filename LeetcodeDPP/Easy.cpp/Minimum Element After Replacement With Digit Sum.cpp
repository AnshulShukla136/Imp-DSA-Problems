// TC = O(nlogn);
// DC = O(1)
class Solution
{
public:
    int digitSum(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int rem = n % 10;
            sum += rem;
            n = n / 10;
        }
        return sum;
    }
    int minElement(vector<int> &nums)
    {
        int mini = INT_MAX;
        for (int x : nums)
        {
            mini = min(mini, digitSum(x));
        }
        return mini;
    }
};