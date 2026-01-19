class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        
        // Prefix sum: pre[i][j] = sum of submatrix (0,0) to (i-1,j-1)
        vector<vector<int>> pre(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pre[i][j] = mat[i-1][j-1]
                          + pre[i-1][j]
                          + pre[i][j-1]
                          - pre[i-1][j-1];
            }
        }
        
        // Function to check if there's a k x k square with sum <= threshold
        auto can = [&](int k) {
            for (int i = k; i <= m; i++) {
                for (int j = k; j <= n; j++) {
                    int sum = pre[i][j]
                            - pre[i-k][j]
                            - pre[i][j-k]
                            + pre[i-k][j-k];
                    if (sum <= threshold) return true;
                }
            }
            return false;
        };
        
        int lo = 0, hi = min(m, n);
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (can(mid)) lo = mid;
            else hi = mid - 1;
        }
        
        return lo;
    }
};