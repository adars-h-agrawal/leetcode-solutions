class Solution {
public:
    vector<string> ans;
    
    void dfs(string&s, int i) {
        if (i == s.size()) {
            ans.push_back(s);
            return;
        }

        dfs(s, i + 1);

        if (isalpha(s[i])) {
            s[i] ^= 32;      // toggle case (ASCII trick)
            dfs(s, i + 1);
            s[i] ^= 32;      // restore
        }
    }

    vector<string> letterCasePermutation(string s) {
        dfs(s, 0);
        return ans;
    }
};