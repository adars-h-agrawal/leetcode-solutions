class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;
        long long ways = 1;
        int seats = 0;
        int plantsBetween = 0;
        bool firstGroup = true;

        for (char c : corridor) {
            if (c == 'S') {
                seats++;

                // When we reach a new group of seats
                if (seats % 2 == 1 && !firstGroup) {
                    ways = (ways * (plantsBetween + 1)) % MOD;
                    plantsBetween = 0;
                }

                if (seats == 2) firstGroup = false;
            } else if (c == 'P' && seats >= 2 && seats % 2 == 0) {
                plantsBetween++;
            }
        }

        // Must have at least 2 seats and even number of seats
        if (seats < 2 || seats % 2 != 0) return 0;

        return ways;
    }
};