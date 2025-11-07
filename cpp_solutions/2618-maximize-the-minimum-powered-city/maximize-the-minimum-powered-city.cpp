class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        // Build initial prefix‐sum of “power” at each city from existing stations
        vector<long long> d(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int left = max(0, i - r);
            int right = min(n - 1, i + r);
            d[left] += stations[i];
            d[right + 1] -= stations[i];
        }
        vector<long long> s(n, 0);
        long long acc = 0;
        for (int i = 0; i < n; i++) {
            acc += d[i];
            s[i] = acc;
        }

        auto check = [&](long long x)->bool {
            // Can we make every city have at least power x using ≤ k added stations?
            vector<long long> addDiff(n + 1, 0);
            long long addedAcc = 0;
            long long remaining = k;
            for (int i = 0; i < n; i++) {
                addedAcc += addDiff[i];
                long long currentPower = s[i] + addedAcc;
                if (currentPower < x) {
                    long long need = x - currentPower;
                    if (need > remaining) return false;
                    remaining -= need;
                    // place these “need” new stations at position j = min(i + r, n-1)
                    int j = min(n - 1, i + r);
                    int left = max(0, j - r);
                    int right = min(n - 1, j + r);
                    addDiff[left] += need;
                    addDiff[right + 1] -= need;
                    addedAcc += need;
                }
            }
            return true;
        };

        long long lo = 0, hi = accumulate(stations.begin(), stations.end(), 0LL) + k + 1;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            if (check(mid)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};