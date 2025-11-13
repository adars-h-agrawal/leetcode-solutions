class Solution {
public:
    long long maxOperations(const string &s) {
        long long ans = 0;
        long long ones = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++ones;
            } else {
                // s[i] == '0'
                // If the previous character was '1', we can move ALL the ones seen so far past
                if (i > 0 && s[i - 1] == '1') {
                    ans += ones;
                }
            }
        }
        return ans;
    }
};