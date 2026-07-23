class Solution {
public:
    int missingNumber(vector<int>& nums) {
        map<int, int> frq;
        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            frq[i] = 0;
        }

        for (int n : nums) {
            frq[n]++;
        }

        for (auto [a,b] : frq) {
            if (b == 0) return a;
        }
        return 0;
    }
};