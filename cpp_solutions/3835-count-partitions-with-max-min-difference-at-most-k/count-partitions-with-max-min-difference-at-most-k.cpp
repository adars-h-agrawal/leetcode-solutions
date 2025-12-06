#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1000000007;
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n+1, 0), prefix(n+1, 0);
        dp[0] = 1;
        prefix[0] = 1;

        deque<int> dqMin, dqMax;  // for maintaining min & max in window
        int left = 0;

        for (int right = 0; right < n; right++) {
            // push nums[right] into deques
            while (!dqMin.empty() && nums[dqMin.back()] >= nums[right]) dqMin.pop_back();
            dqMin.push_back(right);
            while (!dqMax.empty() && nums[dqMax.back()] <= nums[right]) dqMax.pop_back();
            dqMax.push_back(right);

            // shrink window from left if invalid
            while (!dqMin.empty() && !dqMax.empty() && nums[dqMax.front()] - nums[dqMin.front()] > k) {
                if (dqMin.front() == left) dqMin.pop_front();
                if (dqMax.front() == left) dqMax.pop_front();
                left++;
            }

            // now all subarrays from left..right are valid
            // dp for first (right+1) elements:
            // sum dp[left .. right] = prefix[right] - prefix[left-1]
            long long sum = prefix[right] - (left - 1 >= 0 ? prefix[left - 1] : 0);
            if (sum < 0) sum += MOD;
            dp[right + 1] = sum % MOD;

            prefix[right + 1] = (prefix[right] + dp[right + 1]) % MOD;
        }

        return dp[n];
    }
};