class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.size(), end = n - 1;
        while (end >= 0) {
            while (end >= 0 && s[end] == ' ') end--;
            if (end < 0) break; // all spaces or done

            int start = end;
            while (start >= 0 && s[start] != ' ') start--;

            if (!ans.empty()) ans += ' ';
            ans += s.substr(start + 1, end - start);
            end = start - 1;
        }
        return ans;
    }
};