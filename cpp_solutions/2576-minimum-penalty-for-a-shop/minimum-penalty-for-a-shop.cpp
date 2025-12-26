class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0;
        // Initial penalty if we close at hour 0: all 'Y' are missed
        for (char c : customers) {
            if (c == 'Y') penalty++;
        }

        int minPenalty = penalty;
        int bestHour = 0;

        // Try closing after each hour i (i from 0 to n-1)
        for (int i = 0; i < (int)customers.size(); i++) {
            if (customers[i] == 'Y') {
                penalty--;   // no longer a missed customer
            } else { // 'N'
                penalty++;   // idle open hour
            }

            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = i + 1; // closing after hour i
            }
        }
        return bestHour;
    }
};