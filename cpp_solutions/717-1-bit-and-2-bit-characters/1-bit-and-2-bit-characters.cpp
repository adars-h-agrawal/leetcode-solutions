class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        int n = bits.size();
        
        while (i < n - 1) {
            if (bits[i] == 1) {
                i += 2;  // 2-bit character
            } else {
                i += 1;  // 1-bit character
            }
        }
        
        // If we ended exactly at the last index, last char is 1-bit
        return i == n - 1;
    }
};