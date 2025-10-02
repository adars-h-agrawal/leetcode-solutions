class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // dp[i][j] = min cost to triangulate b/w vertex i & j

        for (int len = 2; len < n; len++) { // length of sub-polygon
            for (int i = 0; i + len < n; i++) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    int cost = dp[i][k] + dp[k][j] + values[i] * values[j] * values[k];
                    dp[i][j] = min(dp[i][j], cost);

                }
            }
        }
        return dp[0][n-1];
    }
};