class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n ==0 || k == 0) return 0;

        // dp[j][0] = flat
        // dp[j][1] = holding long
        // dp[j][2] = holding short
        vector<vector<long long>> dp(k + 1, vector<long long>(3, 0));
        vector<vector<long long>> ndp(k + 1, vector<long long>(3, 0));

        // Day 0 initialization
        for (int j = 1; j <= k; j++) {
            dp[j][0] = 0;
            dp[j][1] = -prices[0];
            dp[j][2] = prices[0];
        }

        // Process each day
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                // Stay flat or close a position
                ndp[j][0] = max({
                    dp[j][0], 
                    dp[j][1] + prices[i], // sell long
                    dp[j][2] - prices[i]  // close short
                });

                // Hold long or open new long
                ndp[j][1] = max(
                    dp[j][1], 
                    dp[j - 1][0] - prices[i]
                );

                // Hold short or open new short
                ndp[j][2] = max(
                    dp[j][2], 
                    dp[j - 1][0] + prices[i]
                );
            }
            dp = ndp;
        }
        return dp[k][0];
    }
};