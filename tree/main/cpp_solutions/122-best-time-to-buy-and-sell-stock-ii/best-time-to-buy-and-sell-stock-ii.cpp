class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], profit = 0, n = prices.size();

        for (int i = 0; i < n; i++) {
            buy = min(buy, prices[i]);
            if (prices[i] > buy) {
                if (i == n-1 || prices[i] > prices[i + 1]) {
                    profit += prices[i] - buy;
                    buy = 3 * 10e4;
                }
            }
        }
        return profit;
    }
};