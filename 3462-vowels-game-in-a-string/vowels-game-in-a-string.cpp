class Solution {
public:
    bool doesAliceWin(string s) {
        int even = 1, odd = 0, parity = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (char c : s) {
            if (vowels.count(c)) parity ^= 1; // flip parity
            if (parity == 0) even++;
            else odd++;
        }
        return even > 0 && odd > 0;  // safe check
    }
};