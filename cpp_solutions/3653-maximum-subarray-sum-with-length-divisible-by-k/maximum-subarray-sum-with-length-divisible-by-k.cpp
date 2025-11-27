#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        // minPrefix[i] = minimum prefix sum among all positions whose index % k == i
        vector<long long> minPrefix(k, LLONG_MAX / 2);
        // we consider prefix sum before starting any elements as at index = -1,
        // which corresponds to (i % k) = (k - 1), so initialize that to 0
        minPrefix[k - 1] = 0;

        long long prefix = 0;
        long long ans = LLONG_MIN;

        for (int i = 0; i < (int)nums.size(); i++) {
            prefix += nums[i];
            // if we subtract the minimum prefix for same i%k, we get a subarray
            // whose length is divisible by k
            ans = max(ans, prefix - minPrefix[i % k]);
            // update minPrefix for this residue class
            minPrefix[i % k] = min(minPrefix[i % k], prefix);
        }

        return ans;
    }
};