class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};
        for (int n : nums) {
            int sz = ans.size();
            for (int i = 0; i < sz; i++) {
                vector<int> temp = ans[i];
                temp.push_back(n);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};