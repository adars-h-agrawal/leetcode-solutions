class Solution {
public:
    bool checkDivisibility(int n) {
        int ans = 0, copy = n, t1 = 0, t2 = 1;
        while (copy > 0) {
            t1 += copy % 10;
            t2 *= copy % 10;
            copy /= 10;
        }
        return (n % (t1 + t2) == 0);
    }
};