class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long S = 0;
        for (int x : nums) S += x;
        return S % k;
    }
};