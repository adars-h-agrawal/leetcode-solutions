class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size(), sign = 1;
        long ans = 0;

        // skip leading whitespaces
        while (i < n && s[i] == ' ') i++;

        // handle sign
        if (i < n && (s[i] == '+' || s[i] == '-'))
            sign = (s[i++] == '+') ? 1 : -1;

        // convert digits to numbers
        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + sign * (s[i++] - '0');
            if (ans >= INT_MAX) return INT_MAX;
            if (ans <= INT_MIN) return INT_MIN;
        }
        return ans;
    }
};