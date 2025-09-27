class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;

        unordered_map<char, string> digitToLetters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        backtrack(digits, 0, "", result, digitToLetters);
        return result;
    }

    void backtrack(const string& digits, int index, string combination, vector<string>& result, const unordered_map<char, string>& digitToLetters) {
        if (index == digits.length()) {
            result.push_back(combination);
            return;
        }

        string letters = digitToLetters.at(digits[index]);
        for (char letter : letters) {
            backtrack(digits, index + 1, combination + letter, result, digitToLetters);
        }
    }
};