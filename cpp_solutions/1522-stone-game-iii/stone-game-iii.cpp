class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        // dp[i] = maximum score difference (current player - opponent)
        // starting from index i
        vector<int> dp(n + 1, 0);

        // Fill from back to front
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = INT_MIN;

            int sum = 0;

            // Try taking 1, 2, or 3 stones
            for (int k = 0; k < 3 && i + k < n; k++) {
                sum += stoneValue[i + k];

                // Current gain - opponent's best difference
                dp[i] = max(dp[i], sum - dp[i + k + 1]);
            }
        }

        if (dp[0] > 0)
            return "Alice";
        else if (dp[0] < 0)
            return "Bob";
        else
            return "Tie";
    }
};