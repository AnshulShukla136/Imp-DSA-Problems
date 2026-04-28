class Solution {
public:
    int memo(int target, int idx, vector<int> &denominations, vector<vector<int>> &dp){
        if(target == 0) return 1;
        if(idx < 0) return 0;
        if(dp[target][idx] != -1) return dp[target][idx];
        //not taken
        int not_taken = memo(target, idx-1, denominations, dp);
        //taken 
        int taken = 0;
        if(target - denominations[idx] >= 0){
            taken = memo(target - denominations[idx], idx, denominations, dp);
        }
        return dp[target][idx] = taken + not_taken;
    }
    vector<int> findCoins(vector<int>& numWays) {
        vector<int> denominations;
        for(int i = 0; i < numWays.size(); i++){
            
                int n = denominations.size();
                vector<vector<int>> dp(i+2, vector<int>(n, -1));
                int ways = memo(i+1, n-1, denominations, dp);
                if(ways + 1 == numWays[i]) denominations.push_back(i+1);
                else if(numWays[i] > ways +1) return {};
                else if(ways > numWays[i]) return {};
            
        }
    
    return denominations;
    }

    
};



class Solution {
public:
    int dp[101][101];
    int ways(int n , vector<int>&coins , int in){
        if(n == 0){
            return 1 ;
        }
        if(n < 0 || in >= coins.size()){
            return 0;
        }

        if(dp[n][in] != -1){
            return dp[n][in];
        }

        int ans = ways(n , coins , in+1) + ways(n-coins[in] , coins , in);


        return dp[n][in] = ans;
    }

    vector<int> findCoins(vector<int>& numWays) {
        vector<int>coin;

        for(int i=0 ; i<numWays.size() ; i++){
            memset(dp , -1 , sizeof(dp));
            int totalWaysWithoutCoin = ways(i+1 , coin , 0);
            if( totalWaysWithoutCoin == numWays[i]){
                continue;
            }
            else{
                coin.push_back(i+1);
                memset(dp , -1 , sizeof(dp));
                int totalWaysWithCoin = ways(i+1 , coin , 0);
                if(numWays[i] != totalWaysWithCoin){
                    coin = vector<int>();
                    return coin;
                }
            }
        }

        return coin ;
    }
};

void solve(int n, vector<int>ans,vector<char>&chars, int i,char prev){
        if(i >= n)return;
        if(chars[i] != prev){
            
        }

    }
    string getHappyString(int n, int k) {
        vector<string>ans;
        vector<char>chars(3);
        chars.push_back('a');
        chars.push_back('b');
        chars.push_back('c');
        solve(n, ans,chars, 0,'l');
    }  