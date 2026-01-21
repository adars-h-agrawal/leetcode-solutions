class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int a : arr) {
            mp[a]++;
        }
        unordered_set<int> freq;
        for (auto [a, b] : mp) {
            if (freq.count(b)) return false;
            freq.insert(b);
        }
        return true;
    }
};