class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        unordered_map<char, int> m1, m2;

        for (char c : word1) m1[c]++;
        for (char c : word2) m2[c]++;

        // 1. same set of chars
        for (auto [a, b] : m1) {
            if (m2.find(a) == m2.end()) return false;
        }

        // 2. same multiset of frequencies
        vector<int> f1, f2;
        for (auto [a, b] : m1) f1.push_back(b);
        for (auto [a, b] : m2) f2.push_back(b);

        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());

        return f1 == f2;
    }
};