class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return 0;

        sort(nums.begin(), nums.end());
        int i = 0, wSize = 1;

        for (int j = 0; j < n; j++) {
            while (i <= j && nums[j] > 1LL * k * nums[i]) i++;
            wSize = max(wSize, j - i + 1);
        }
        return n - wSize;
    }
};