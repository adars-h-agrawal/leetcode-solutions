class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1, n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = n-1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }
        return ans;
    }
};

/*

1  2  3  4
1  1  2  6
24 12 8  6    

*/