class Solution {
public:
    int maxProduct(int n) {
        vector<int> nums;
        while (n > 0) {
            int temp = n % 10;
            n /= 10;
            nums.push_back(temp);
        }
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[0] * nums[1];
    }
};