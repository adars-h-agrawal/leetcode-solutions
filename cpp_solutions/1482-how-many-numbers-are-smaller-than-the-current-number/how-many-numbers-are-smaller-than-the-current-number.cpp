class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> frq(101, 0);

        for (int n : nums) {
            frq[n]++;
        }

        for (int i = 1; i <= 100; i++) {
            frq[i] += frq[i - 1];
        }

        vector<int> ans;

        for (int n : nums) {
            if (n == 0) ans.push_back(0);
            else ans.push_back(frq[n-1]);
        }
        return ans;
    }
};