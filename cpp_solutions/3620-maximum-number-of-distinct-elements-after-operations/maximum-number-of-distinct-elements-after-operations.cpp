class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        long long occupied = LLONG_MIN;
        for (long long x : nums) {
            if (occupied < x + k) {
                occupied = max(occupied + 1, x - k);
                ans++;
            }
        }
        return ans;
    }
};