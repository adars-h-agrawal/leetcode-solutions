class Solution {
public:
    bool isVowel(char c) {
        return string("aeiou").find(c) != string::npos;
    }

    int maxFreqSum(string s) {
        unordered_map<char, int> vowels, consonants;
        for (char c : s) {
            if (isVowel(c)) vowels[c]++;
            else consonants[c]++;
        }

        int maxV = 0, maxC = 0;
        for (auto& [ch, freq] : vowels) maxV = max(maxV, freq);
        for (auto& [ch, freq] : consonants) maxC = max(maxC, freq);

        return maxV + maxC;
    }
};