class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long evenSum = n * (n + 1);
        long long oddSum = n * n;
        return gcd(evenSum , oddSum);
    }
};