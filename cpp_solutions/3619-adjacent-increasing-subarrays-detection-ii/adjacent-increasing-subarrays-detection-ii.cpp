class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int prev = 0;      // length of previous strictly increasing run
        int cur = 1;       // length of current increasing run (at least 1)
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                ++cur;
            } else {
                // boundary: the increasing run ends here
                ans = max(ans, cur / 2);
                ans = max(ans, min(prev, cur));
                
                prev = cur;
                cur = 1;
            }
        }
        
        ans = max(ans, cur / 2);
        ans = max(ans, min(prev, cur));
        
        return ans;
    }
};