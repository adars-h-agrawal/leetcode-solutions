class Solution {
public:
    int numberOfSubstrings(string s) {
        // c1[i] = number of '1's seen before the i-th '0'
        vector<int> onesBeforeZero = {0};

        int count0 = 0;
        int count1 = 0;
        long long total = 0;

        for (char ch : s) {
            if (ch == '1') {
                ++count1;
            } else {
                // ch == '0'
                ++count0;
                onesBeforeZero.push_back(count1);
            }

            // Substrings ending at current index with exactly one '0'
            total += count1 - onesBeforeZero[count0];

            // Substrings with ≥2 zeros and satisfying (num0^2 ≤ num1)
            for (int prev0 = count0 - 1; prev0 >= 0; --prev0) {
                int num0 = count0 - prev0;
                int minOnesNeeded = num0 * num0;

                if (minOnesNeeded > count1) break;

                int hi = count1 - onesBeforeZero[prev0];       // max ones available
                int lo = count1 - onesBeforeZero[prev0 + 1];   // min ones available

                if (hi < minOnesNeeded) continue;

                int lowBound = max(lo, minOnesNeeded);
                total += max(0, hi - lowBound + 1);
            }
        }

        return total;
    }
};