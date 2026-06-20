class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});

        bool hasN = false;
        for (auto &r : restrictions) {
            if (r[0] == n) {
                hasN = true;
                break;
            }
        }

        if (!hasN) {
            restrictions.push_back({n, n-1});
        }

        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        // forward pass
        for (int i = 1; i < m; i++) {
            int dist = restrictions[i][0] - restrictions[i - 1][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i-1][1] + dist);
        }

        // backward pass
        for (int i = m - 2; i >= 0; i--) {
            int dist = restrictions[i+1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i+1][1] + dist);
        }

        long long ans = 0;

        // compute maximum peak in each interval
        for (int i = 1; i < m; i++) {
            long long leftPos = restrictions[i - 1][0];
            long long leftH   = restrictions[i - 1][1];

            long long rightPos = restrictions[i][0];
            long long rightH   = restrictions[i][1];

            long long dist = rightPos - leftPos;

            long long peak = (leftH + rightH + dist) / 2;
            ans = max(ans, peak);
        }

        return (int)ans;
    }
};