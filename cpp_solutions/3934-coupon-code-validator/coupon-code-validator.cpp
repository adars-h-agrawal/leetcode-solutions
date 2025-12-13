class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<pair<int, string>> valid;

        // Define order priority for business lines
        unordered_map<string, int> order = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        auto isValidCode = [&](const string &s) {
            if (s.empty()) return false;
            for (char c : s) {
                // check only alphanumeric or underscore
                if (!(isalnum(c) || c == '_')) return false;
            }
            return true;
        };

        for (int i = 0; i < n; i++) {
            // check active
            if (!isActive[i]) continue;

            // check valid business line
            if (order.find(businessLine[i]) == order.end()) continue;

            // check code format
            if (!isValidCode(code[i])) continue;

            // add (business order, code) for sorting
            valid.push_back({ order[businessLine[i]], code[i] });
        }

        // sort by business priority then lex order of code
        sort(valid.begin(), valid.end(), [](auto &a, auto &b) {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second < b.second;
        });

        // extract only coupon strings
        vector<string> result;
        for (auto &p : valid)
            result.push_back(p.second);

        return result;
    }
};