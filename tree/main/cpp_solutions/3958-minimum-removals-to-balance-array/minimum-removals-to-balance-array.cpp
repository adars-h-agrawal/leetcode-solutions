class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, ans = n;
        if (n < 2) return 0;
        sort(nums.begin(), nums.end());
        
        for (int j = 1; j < n; j++) {
            while (nums[j] > 1LL * k * nums[i]) i++;
            ans = min(ans, n - (j - i + 1));
        }
        return ans;
    }
};