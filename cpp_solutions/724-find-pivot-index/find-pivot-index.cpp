class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, temp = 0;
        for (int num : nums) {
            sum += num;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (temp == sum - temp - nums[i]) return i;
            temp += nums[i];
        }
        return -1;
    }
};