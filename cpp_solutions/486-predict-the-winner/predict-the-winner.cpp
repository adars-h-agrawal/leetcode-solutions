class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp, vector<vector<bool>>& vis) {
        if (i == j) return nums[i];
        if (vis[i][j]) return dp[i][j];

        vis[i][j] = true;

        int takeLeft = nums[i] - solve(i+1, j, nums, dp, vis);
        int takeRight = nums[j] - solve(i, j-1, nums, dp, vis);
        dp[i][j] = max(takeLeft, takeRight);
        return dp[i][j];
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        return solve(0, n-1, nums, dp, vis) >= 0;
    }
};