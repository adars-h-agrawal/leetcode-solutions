class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        stack<int> stk;
        stk.push(0);  // sentinel: treat 0 as base (already zero)

        for (int num : nums) {
            // Pop until stack top ≤ current num
            while (!stk.empty() && stk.top() > num) {
                stk.pop();
            }
            // If current num is > 0 and either stack is empty or stack.top() < num
            if (num > 0 && (stk.empty() || stk.top() < num)) {
                ++ans;
                stk.push(num);
            }
            // If num == 0, we do nothing: it's already zero
        }

        return ans;
    }
};