class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, buy = prices[0];
        for (int p : prices) {
            buy = min(buy, p);
            profit = max(profit, p - buy);
        }
        return profit;
    }
};