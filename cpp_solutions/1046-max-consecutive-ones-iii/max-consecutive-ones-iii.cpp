class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, ans = 0, zeros = 0, n = nums.size();
        for (right; right < n; right++) {
            if (nums[right] == 0) zeros++;

            while (zeros > k) {
                if (nums[left++] == 0) zeros--;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};