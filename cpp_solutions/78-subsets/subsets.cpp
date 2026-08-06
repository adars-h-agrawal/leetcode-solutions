class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;

    void dfs(int idx, vector<int>& nums) {
        if (idx == nums.size()) {
            ans.push_back(cur);
            return;
        }

        // don't take
        dfs(idx + 1, nums);

        // take
        cur.push_back(nums[idx]);
        dfs(idx + 1, nums);
        cur.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }
};