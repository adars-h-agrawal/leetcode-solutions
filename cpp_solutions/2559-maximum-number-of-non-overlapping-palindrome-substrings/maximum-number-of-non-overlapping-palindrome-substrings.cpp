class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (k == 1) return n;

        int res = 0;

        auto check = [&](int l, int r) {
            for (; l < r; l++, r--)
                if (s[l] != s[r]) return 0;
            return 1;
        };

        for (int i = 0; i <= n - k; i++) {
            if (check(i, i + k - 1)) {
                res++;
                i += k - 1;
            } else if (i < n - k && check(i, i + k)) {
                res++;
                i += k;
            }
        }

        return res;
    }
};