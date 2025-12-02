class Solution {
public:
    static constexpr long long MOD = 1'000'000'007;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<long long, long long> freq;

        // Count points by y-level.
        for (auto &p : points) {
            long long y = p[1];
            freq[y]++;
        }

        vector<long long> pairs;
        pairs.reserve(freq.size());

        // Compute C(cnt, 2) for each y-level.
        for (auto &kv : freq) {
            long long c = kv.second;
            if (c >= 2) {
                long long val = (c * (c - 1) / 2) % MOD;
                pairs.push_back(val);
            }
        }

        long long ans = 0;
        long long sum = 0;

        // For each unordered pair: sum(pairs[i] * pairs[j])
        for (long long v : pairs) {
            ans = (ans + v * sum) % MOD;
            sum = (sum + v) % MOD;
        }

        return ans % MOD;
    }
};