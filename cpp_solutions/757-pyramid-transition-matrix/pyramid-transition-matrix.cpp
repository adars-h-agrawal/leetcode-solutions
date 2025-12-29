#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_set<string> bad; // memo for impossible rows

    bool dfs(const string& row) {
        if (row.size() == 1) return true;
        if (bad.count(row)) return false;

        string next(row.size() - 1, ' ');
        return buildNext(row, 0, next);
    }

    bool buildNext(const string& row, int idx, string& next) {
        if (idx == next.size())
            return dfs(next);

        string key = row.substr(idx, 2);
        if (!mp.count(key)) return false;

        for (char c : mp[key]) {
            next[idx] = c;
            if (buildNext(row, idx + 1, next))
                return true;
        }
        bad.insert(row);
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto& s : allowed)
            mp[s.substr(0, 2)].push_back(s[2]);

        return dfs(bottom);
    }
};