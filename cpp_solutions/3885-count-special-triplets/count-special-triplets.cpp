class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, long long> left, right;
        int n = nums.size();
        // build right map: count all elements initially
        for (int x : nums) {
            right[x]++;
        }
        
        long long ans = 0;
        for (int x : nums) {
            // move current x from right to middle
            right[x]--;
            long long target = (long long)x * 2;
            // count how many on left == x*2, and how many on right == x*2
            long long cntL = 0, cntR = 0;
            auto itL = left.find(target);
            if (itL != left.end()) cntL = itL->second;
            auto itR = right.find(target);
            if (itR != right.end()) cntR = itR->second;
            
            ans = (ans + cntL * cntR) % MOD;
            
            // add current x to left for future
            left[x]++;
        }
        
        return (int)ans;
    }
};