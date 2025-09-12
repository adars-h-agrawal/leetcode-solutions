class Solution {
public:
    bool doesAliceWin(const string &s) {
        for (char c: s) {
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') 
                return true;
        }
        return false;
    }
};