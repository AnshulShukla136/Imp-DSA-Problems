class Solution {
public:
    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            long long prod = 1;
            long long gc = nums[i];
            long long lc = nums[i];
            for(int j = i; j < n; j++){
                if(prod > LLONG_MAX / nums[j]){
                    break;
                }
                prod = prod * nums[j];
                gc = gcd(nums[j], gc);
                lc = lcm(nums[j], lc);

                if(prod == gc * lc){
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};