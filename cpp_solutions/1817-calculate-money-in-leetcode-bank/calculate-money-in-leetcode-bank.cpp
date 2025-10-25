class Solution {
public:
    int totalMoney(int n) {
        int ans = 0, weekStart = 1;
        while (n > 0) {
            for (int day = 0; day < min(7, n); ++day)
                ans += weekStart + day;
            weekStart++;
            n -= 7;
        }
        return ans;
    }
};