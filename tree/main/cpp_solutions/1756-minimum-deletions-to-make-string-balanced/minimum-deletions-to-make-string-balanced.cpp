class Solution {
public:
    int minimumDeletions(string s) {
        int deletions = 0, bCount = 0;
        for (char c : s) {
            if (c == 'b') bCount++;
            else {
                deletions = min(deletions + 1, bCount);
            }
        }
        return deletions;
    }
};