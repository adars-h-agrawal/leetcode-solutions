class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<long long> dp(n, 0LL);
        // dp[i] = the earliest time wizard i finishes the current potion (or is free)
        
        for (int j = 0; j < m; ++j) {
            long long x = mana[j];
            // Forward pass: enforce constraints with previous wizard and next wizard
            for (int i = 0; i < n; ++i) {
                if (i >= 1) {
                    dp[i] = max(dp[i], dp[i-1]);
                }
                long long cost = (long long)skill[i] * x;
                if (i + 1 < n) {
                    dp[i] = max(dp[i], dp[i+1] - cost);
                }
                dp[i] += cost;
            }
            // Backward pass: adjust to ensure no one starts too early
            for (int i = n - 1; i > 0; --i) {
                // We know dp[i] is correct final finish time for wizard i on this potion
                // So wizard i−1 must finish by dp[i] − skill[i]*mana[j]
                dp[i-1] = dp[i] - (long long)skill[i] * x;
            }
        }
        
        return dp[n-1];
    }
};