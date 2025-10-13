#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        if (words.empty()) return ans;
        ans.push_back(words[0]);
        for (int i = 1; i < (int)words.size(); i++) {
            if (!isAnagram(ans.back(), words[i])) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
    
private:
    bool isAnagram(const string &a, const string &b) {
        if (a.size() != b.size()) return false;
        int cnt[26] = {0};
        for (char c : a) cnt[c - 'a']++;
        for (char c : b) {
            if (--cnt[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};