class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        map<int, int> frq;
        int s = INT_MAX, b = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            frq[nums[i]]++;
            if (nums[i] < s) s = nums[i];
            if (nums[i] > b) b = nums[i];
        }
        while (s < b) {
            if (frq[s] == 0) ans.push_back(s);
            s++;
        }
        return ans;
    }
};