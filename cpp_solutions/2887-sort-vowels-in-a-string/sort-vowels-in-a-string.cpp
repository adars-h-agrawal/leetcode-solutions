class Solution {
public:
    string sortVowels(string s) {
        string vowels;
        string vowelSet = "AEIOUaeiou";
        
        // Collect vowels
        for (char c : s)
            if (vowelSet.find(c) != string::npos)
                vowels += c;

        // Sort the vowels
        sort(vowels.begin(), vowels.end());

        // Replace vowels in original string with sorted ones
        int j = 0;
        for (char& c : s)
            if (vowelSet.find(c) != string::npos)
                c = vowels[j++];

        return s;
    }
};