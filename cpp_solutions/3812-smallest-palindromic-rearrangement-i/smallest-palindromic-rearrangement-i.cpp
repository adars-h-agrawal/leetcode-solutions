class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> frq;
        string left = "";
        char mid = '\0';

        for (char c : s) {
            frq[c]++;
        }

        for (auto &[ch, count] : frq) {
            if (count % 2 == 1)
                mid = ch;

            left += string(count / 2, ch);
        }

        string ans = left;
        if (mid) ans += mid;

        reverse(left.begin(), left.end());
        ans += left;
        return ans;
    }
};