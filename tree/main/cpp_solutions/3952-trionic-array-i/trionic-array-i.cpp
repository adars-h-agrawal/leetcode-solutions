class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        // phase 1 : strictly increasing
        int i = 1;
        while (i < n && nums[i] > nums[i - 1])i++;
        if (i == 1 || i == n) return false;

        // phase 2 : strictly decreasing
        int mid = i;
        while (i < n && nums[i] < nums[i - 1]) i++;
        if (i == mid || i == n) return false;

        // phase 3 : strictly increasing
        while (i < n && nums[i] > nums[i - 1])i++;

        return i == n;
    }
};