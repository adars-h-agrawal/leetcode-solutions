class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size());

        for (int x : nums) {
            // If x == 2, impossible
            if (x == 2) {
                ans.push_back(-1);
            } else {
                // Find first 0 bit starting from bit position 1
                for (int i = 1; i < 32; ++i) {
                    if (((x >> i) & 1) == 0) {
                        // Flip the (i-1)th bit of x to get minimal a
                        ans.push_back(x ^ (1 << (i - 1)));
                        break;
                    }
                }
            }
        }
        return ans;
    }
};