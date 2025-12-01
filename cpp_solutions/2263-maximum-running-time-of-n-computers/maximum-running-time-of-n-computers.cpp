class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long left = 0, right = 0;
        for (long long b : batteries) right += b; // total battery sum

        right /= n; // upper bound for time

        auto canRun = [&](long long t) {
            long long total = 0;
            for (long long b : batteries) {
                total += min(b, t);
                if (total >= t * n) return true;
            }
            return total >= t * n;
        };

        while (left < right) {
            long long mid = (left + right + 1) / 2;
            if (canRun(mid)) 
                left = mid;
            else 
                right = mid - 1;
        }
        return left;
    }
};