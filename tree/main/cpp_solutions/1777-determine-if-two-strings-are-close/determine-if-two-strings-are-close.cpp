class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        unordered_map<char, int> f1, f2;

        for (char c : word1) f1[c]++;
        for (char c : word2) f2[c]++;

        for (auto [a, b] : f1) {
            if (f2.find(a) == f2.end()) return false;
        }

        vector<int> l1, l2;
        for (auto [a, b] : f1) l1.push_back(b);
        for (auto [a, b] : f2) l2.push_back(b);
        
        sort(l1.begin(), l1.end());
        sort(l2.begin(), l2.end());

        return l1 == l2;
    }
};