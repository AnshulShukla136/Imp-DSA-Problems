// 122 - best time to buy sell stock 2  can also be done by greedy

// 123 - best time to buy sell stock 3

#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int> &prices, int n, int idx, int buy, vector<vector<int>> &dp)
{
    if (idx >= n)
        return 0;
    if (dp[idx][buy] != -1)
        return dp[idx][buy];
    int take = 0;
    int not_take = 0;
    if (buy <= 3)
    {
        if (buy % 2 == 0)
        {
            take = -prices[idx] + solve(prices, n, idx + 1, buy + 1, dp);
            not_take = solve(prices, n, idx + 1, buy, dp);
        }
        else
        {
            take = prices[idx] + solve(prices, n, idx + 1, buy + 1, dp);
            not_take = solve(prices, n, idx + 1, buy, dp);
        }
    }
    return dp[idx][buy] = max(take, not_take);
}
int main()
{
    cout << "Enter size: ";
    int n;
    cin >> n;
    cout << endl;
    vector<int> prices(n, -1);
    cout << "Enter values ";
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(5, -1));
    cout << solve(prices, n, 0, 0, dp);
}

// 188 - best time to buy sell stock 4

class Solution
{
public:
    int solve(vector<int> &prices, int n, int k, int idx, int buy, vector<vector<int>> &dp)
    {
        if (idx >= n)
            return 0;
        if (dp[idx][buy] != -1)
            return dp[idx][buy];
        int take = 0;
        int not_take = 0;
        if (buy <= (2 * k - 1))
        {
            if (buy % 2 == 0)
            {
                take = -prices[idx] + solve(prices, n, k, idx + 1, buy + 1, dp);
                not_take = solve(prices, n, k, idx + 1, buy, dp);
            }
            else
            {
                take = prices[idx] + solve(prices, n, k, idx + 1, buy + 1, dp);
                not_take = solve(prices, n, k, idx + 1, buy, dp);
            }
        }
        return dp[idx][buy] = max(take, not_take);
    }
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, -1));
        return solve(prices, n, k, 0, 0, dp);
    }
};

// all best time to buy and sell stock question except strategy one\

2054. Two overlapping events very important binary search + DP

    1235. Maximum profit job scheduling extended of 2054   
    
   45. jump game 2
