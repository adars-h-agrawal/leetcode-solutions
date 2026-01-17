class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long ans = 0;
        int n = bottomLeft.size();

        for (int i = 0; i < n; i++) {
            int x1 = bottomLeft[i][0], y1 = bottomLeft[i][1];
            int x2 = topRight[i][0], y2 = topRight[i][1];

            for (int j = i + 1; j < n; j++) {
                int x3 = bottomLeft[j][0], y3 = bottomLeft[j][1];
                int x4 = topRight[j][0], y4 = topRight[j][1];

                int w = min(x2, x4) - max(x1, x3);
                int h = min(y2, y4) - max(y1, y3);

                int side = min(h, w);
                if (side > 0) {
                    ans = max(ans, 1LL * side *side);
                }
            }
        }
        return ans;
    }
};