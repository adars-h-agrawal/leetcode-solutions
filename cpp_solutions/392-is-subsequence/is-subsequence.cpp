class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s == "") return true;
        if (t == "") return false;
        int i = 0, j = 0, m = s.size(), n = t.size();
        while (j < n) {
            if (s[i] == t[j]) i++;
            j++;
        }
        return i >= m;
    }
};