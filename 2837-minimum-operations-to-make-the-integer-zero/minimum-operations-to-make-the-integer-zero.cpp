class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        using ll = long long;
        for (ll k = 1; k <= 60; ++k) {
            ll x = num1 - k * num2;
            if (x < k) break;  // can't use k terms of 2^i to sum up to x
            // Check if x can be the sum of k powers of two:
            // - x must be at least k (since each 2^i ≥ 1)
            // - bit count (number of 1s) in x must be ≤ k
            if (__builtin_popcountll(x) <= k && k <= x) {
                return (int)k;
            }
        }
        return -1;
    }
};
