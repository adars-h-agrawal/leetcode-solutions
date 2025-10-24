class Solution {
public:
    bool isBalanced(int num) {
        string s = to_string(num);
        vector<int> cnt(10, 0);
        for (char c : s) cnt[c - '0']++;
        for (int d = 0; d < 10; ++d) {
            if (cnt[d] && cnt[d] != d) return false;
        }
        return true;
    }
    
    int nextBeautifulNumber(int n) {
        for (int x = n + 1; ; ++x) {
            if (isBalanced(x)) return x;
        }
    }
};