class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int greatest = 0, n = candies.size();
        vector<bool> ans(n, false);
        for (int i = 0; i < n; i++) {
            greatest = max(greatest, candies[i]);
        }
        for (int i = 0; i < n; i++) {
            if (candies[i] + extraCandies >= greatest) {
                ans[i] = true;
            }
        }
        return ans;
    }
};