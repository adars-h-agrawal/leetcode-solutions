class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> rowMp; // frequency of each row
        for (int i = 0; i < n; i++) {
            rowMp[grid[i]]++;
        }

        int ans = 0;
        for (int j = 0; j < n; j++) {
            vector<int> colVc;
            for (int i = 0; i < n; i++) {
                colVc.push_back(grid[i][j]);
            }
            ans += rowMp[colVc];
        }
        return ans;
    }
};