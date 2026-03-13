class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> rows;
        int ans = 0, n = grid.size();

        for (int i = 0; i < n; i++) {
            rows[grid[i]]++;
        }

        for (int j = 0; j < grid[0].size(); j++) {
            vector<int> cols;
            for (int i = 0; i < n; i++) {
                cols.push_back(grid[i][j]);
            }
            ans += rows[cols];
        }
        return ans;
    }
};