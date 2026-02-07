class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        // initial rotten added to q & counted fresh
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) fresh++;
                else if (grid[i][j] == 2) q.push({i, j});
            }
        }
        if (fresh == 0) return 0; // no fresh oranges

        int minutes = -1; // -1 to handle last orange check offset
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c] = q.front(); q.pop();
                for (auto& d : dirs) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                    }
                }
            }
            minutes++;
        }
        return fresh == 0 ? minutes : -1;
    }
};