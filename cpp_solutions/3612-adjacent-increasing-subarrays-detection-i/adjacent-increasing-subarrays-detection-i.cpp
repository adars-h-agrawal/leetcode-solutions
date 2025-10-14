class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int first = 0, second = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i -  1]) {
                second++;
            } else {
                if (second / 2 >= k || min(first, second) >= k) 
                    return true;
                    first = second;
                    second = 1;
            }
        }
        if (second / 2 >= k || min(first, second) >= k) 
            return true;
        return false;
    }
};