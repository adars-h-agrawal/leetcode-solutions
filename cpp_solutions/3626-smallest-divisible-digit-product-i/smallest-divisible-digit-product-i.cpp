class Solution {
public:
    int prod(int n) {
        if (n % 5 == 0 && n % 10 == 0) return 0;
        int ans = 1;
        while (n % 10 > 0) {
            ans *= (n % 10);
            n /= 10;
        }
        return ans;
    }

    int smallestNumber(int n, int t) {
        while (prod(n) % t != 0) n++;
        return n;
    }
};