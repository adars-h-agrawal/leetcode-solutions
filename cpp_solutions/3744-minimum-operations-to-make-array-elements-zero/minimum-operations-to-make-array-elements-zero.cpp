class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            long long sum = 0;
            int maxSteps = 0;

            for (int k = 1; k <= 31; ++k) {
                long long lo = 1LL << (k - 1);
                long long hi = (1LL << k) - 1;
                if (lo > r) break;

                long long a = max(lo, (long long)l);
                long long b = min(hi, (long long)r);
                if (a > b) continue;

                long long count = b - a + 1;
                int steps = (k + 1) / 2;

                sum += count * steps;
                maxSteps = max(maxSteps, steps);
            }
            ans += max((sum + 1) / 2, (long long)maxSteps);
        }
        return ans;
    }
};