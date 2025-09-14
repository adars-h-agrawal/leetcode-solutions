class Solution {
    string low(string s) {
        for (char &c : s) c = tolower(c);
        return s;
    }

    string mask(string s) {
        for (char &c : s) if (string("aeiouAEIOU").find(c) != -1) c = '*';
        return low(s);
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseMap, vowMap;

        for (auto& w : wordlist) {
            caseMap.try_emplace(low(w), w);
            vowMap.try_emplace(mask(w), w);
        }

        vector<string> res;
        for (auto& q : queries) {
            if (exact.count(q)) res.push_back(q);
            else if (caseMap.count(low(q))) res.push_back(caseMap[low(q)]);
            else if (vowMap.count(mask(q))) res.push_back(vowMap[mask(q)]);
            else res.push_back("");
        }
        return res;
    }
};