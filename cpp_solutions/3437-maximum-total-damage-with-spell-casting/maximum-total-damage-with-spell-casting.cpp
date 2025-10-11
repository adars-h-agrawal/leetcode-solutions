class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long, long long> cnt;
        for (int x : power) {
            cnt[x]++;
        }

        vector<long long> vals;
        for (auto &[x, _] : cnt) {
            vals.push_back(x);
        }
        sort(vals.begin(), vals.end());
        int m = vals.size();

        vector<int> nxt(m);
        for (int i = 0; i < m; ++i) {
            // first index j > i where vals[j] > vals[i] + 2
            nxt[i] = upper_bound(vals.begin(), vals.end(), vals[i] + 2) - vals.begin();
        }

        vector<long long> dp(m + 1, 0);
        for (int i = m - 1; i >= 0; --i) {
            // Option 1: skip this value
            long long skip = dp[i + 1];

            // Option 2: take all spells of this damage value
            long long take = vals[i] * cnt[vals[i]] + dp[nxt[i]];

            dp[i] = max(skip, take);
        }

        return dp[0];
    }
};