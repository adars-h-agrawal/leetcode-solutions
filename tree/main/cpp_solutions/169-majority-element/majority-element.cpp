class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0, count = 0;
        for (int n : nums) {
            if (count == 0) ans = n;
            if (ans == n) count++;
            else count--;
        }
        return ans;
    }
};