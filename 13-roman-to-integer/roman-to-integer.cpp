class Solution {
public:
    int func(char c) {
        switch (c) {
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
            default : return 0;
        }
    }

    int romanToInt(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && func(s[i]) < func(s[i + 1])) {
                ans -= func(s[i]);
            } else {
                ans += func(s[i]);
            }
        }
        return ans;
    }
};