class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a = 0, b = 0;

        for (int n : bills) {

            if (n == 5) a++;

            else if (n == 10) {
                if (a <= 0) return false;
                a--;
                b++;
            }

            else {
                if (b > 0 && a > 0) {
                    a--;
                    b--;
                } else if (a >= 3) {
                    a -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

/*
a=2, b=4
*/