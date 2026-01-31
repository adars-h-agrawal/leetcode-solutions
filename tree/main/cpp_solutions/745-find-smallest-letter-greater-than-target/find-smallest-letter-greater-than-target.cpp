class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        int diff = 26;
        for (char c : letters) {
            int temp = (c - '0') - (target - '0');
            if (temp > 0 && temp < diff) {
                ans = c;
                diff = temp;
            } 
        }
        return ans;
    }
};