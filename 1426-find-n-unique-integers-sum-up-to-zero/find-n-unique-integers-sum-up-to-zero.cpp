class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
    
        for (int i = 1; i <= n-1; i+= 2) {
            ans[i-1] = -i;
            ans[i] = i;
        }
        if (n % 2 != 0) ans[n-1] = 0;
        return ans;
    }
};