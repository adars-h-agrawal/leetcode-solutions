class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        vector<int> tmp = nums;
        int n = nums.size();
        while (n > 1) {
            vector<int> cur(n/2);
            for (int i = 0; i < n/2; i++) {
                if (i % 2 == 0) {
                    cur[i] = min(tmp[2*i], tmp[2*i+1]);
                } else {
                    cur[i] = max(tmp[2*i], tmp[2*i+1]);
                }
            }
            tmp = cur;
            n /= 2;
        }
        return tmp[0];
    }
};