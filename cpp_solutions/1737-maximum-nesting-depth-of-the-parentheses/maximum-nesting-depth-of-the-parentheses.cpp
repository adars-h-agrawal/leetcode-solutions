class Solution {
public:
    int maxDepth(string s) {
        int temp = 0, ans = 0;
        for (char c : s) {
            if (c == '(') {
                temp++;
                ans = max(ans, temp);
            } else if (c == ')') temp--;
        }
        return ans;
    }
};