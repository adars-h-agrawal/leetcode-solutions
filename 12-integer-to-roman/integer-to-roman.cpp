class Solution {
public:
    string intToRoman(int n) {
        string s;
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        for (int i = 0; i < 13; i++) {
            while (n >= values[i]) {
                s += roman[i];
                n -= values[i];
            }
        }
        return s;
    }
};