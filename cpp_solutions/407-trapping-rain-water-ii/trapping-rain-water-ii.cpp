class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = m ? heightMap[0].size() : 0;
        if (m < 3 || n < 3) return 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<bool>> seen(m, vector<bool>(n, false));

        // Push border cells
        for (int i = 0; i < m; ++i)
            for (int j : {0, n - 1})
                pq.emplace(heightMap[i][j], i, j), seen[i][j] = true;

        for (int j = 1; j < n - 1; ++j)
            for (int i : {0, m - 1})
                pq.emplace(heightMap[i][j], i, j), seen[i][j] = true;

        int ans = 0, dirs[5] = {0, 1, 0, -1, 0};
        while (!pq.empty()) {
            auto [h, x, y] = pq.top(); pq.pop();
            for (int d = 0; d < 4; ++d) {
                int nx = x + dirs[d], ny = y + dirs[d + 1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || seen[nx][ny]) continue;
                seen[nx][ny] = true;
                ans += max(0, h - heightMap[nx][ny]);
                pq.emplace(max(h, heightMap[nx][ny]), nx, ny);
            }
        }
        return ans;
    }
};