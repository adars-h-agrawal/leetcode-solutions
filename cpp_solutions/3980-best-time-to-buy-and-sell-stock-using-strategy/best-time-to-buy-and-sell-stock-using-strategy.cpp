class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        int half = k / 2;

        // 1. Original profit
        long long originalProfit = 0;
        for (int i = 0; i < n; i++) {
            originalProfit += 1LL * strategy[i] * prices[i];
        }

        // 2. Initial window
        long long firstHalfSum = 0;     // sum(strategy[i] * prices[i])
        long long secondHalfGain = 0;   // sum((1 - strategy[i]) * prices[i])

        for (int i = 0; i < half; i++) {
            firstHalfSum += 1LL * strategy[i] * prices[i];
        }
        for (int i = half; i < k; i++) {
            secondHalfGain += 1LL * (1 - strategy[i]) * prices[i];
        }

        long long maxDelta = secondHalfGain - firstHalfSum;

        // 3. Slide the window
        for (int l = 1; l + k <= n; l++) {
            // Remove outgoing
            firstHalfSum -= 1LL * strategy[l - 1] * prices[l - 1];
            secondHalfGain -= 1LL * (1 - strategy[l + half - 1]) * prices[l + half - 1];

            // Add incoming
            firstHalfSum += 1LL * strategy[l + half - 1] * prices[l + half - 1];
            secondHalfGain += 1LL * (1 - strategy[l + k - 1]) * prices[l + k - 1];

            maxDelta = max(maxDelta, secondHalfGain - firstHalfSum);
        }

        // 4. Either apply best modification or do nothing
        return originalProfit + max(0LL, maxDelta);
    }
};