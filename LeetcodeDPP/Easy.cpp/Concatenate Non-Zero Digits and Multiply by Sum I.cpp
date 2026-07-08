class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long total = 0;
        int tens = 1;
        while(n > 0){
            int rem = n % 10;
            if(rem != 0){
                total += tens * rem;
                tens = tens * 10;
            }
            sum += rem;
            n = n / 10;
        }
        long long ans = total * sum;
        return ans;
    }
};