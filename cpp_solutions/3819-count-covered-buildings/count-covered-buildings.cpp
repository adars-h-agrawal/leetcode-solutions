class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> rowToYs, colToXs;
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            rowToYs[x].push_back(y);
            colToXs[y].push_back(x);
        }
        for (auto &p : rowToYs) {
            auto &v = p.second;
            sort(v.begin(), v.end());
        }
        for (auto &p : colToXs) {
            auto &v = p.second;
            sort(v.begin(), v.end());
        }

        int ans = 0;
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            auto &yb = rowToYs[x];
            auto &xb = colToXs[y];
            if (yb.front() < y && y < yb.back() &&
                xb.front() < x && x < xb.back()) {
                ans++;
            }
        }
        return ans;
    }
};