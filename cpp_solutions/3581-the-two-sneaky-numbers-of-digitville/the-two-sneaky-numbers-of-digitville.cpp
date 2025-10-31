class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int> seen;
        vector<int> ans;
        for (int x : nums) {
            if (seen.count(x))
                ans.push_back(x);
            else
                seen.insert(x);
        }
        return ans;
    }
};