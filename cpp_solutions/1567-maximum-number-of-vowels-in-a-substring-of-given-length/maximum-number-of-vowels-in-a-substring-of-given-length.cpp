class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    int maxVowels(string s, int k) {
        int count = 0, maxi = 0, n = s.size();
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) count++;
        }
        maxi = count;
        
        for (int i = k; i < n; i++) {
            if (isVowel(s[i])) count++;
            if (isVowel(s[i - k])) count--;
            maxi = max(maxi, count);
            if (maxi == k) return k;
        }
        return maxi;
    }
};