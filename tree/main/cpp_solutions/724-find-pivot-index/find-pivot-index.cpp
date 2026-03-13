class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, temp = 0;
        for (int n : nums) sum += n;

        for (int i = 0; i < nums.size(); i++) {
            sum -= nums[i];
            if (temp == sum) return i;
            temp += nums[i];
        } 
        return -1;
    }
};