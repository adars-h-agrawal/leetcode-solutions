class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int i = 0, j = n - 1;

        // Skip cars moving left at the beginning → no one in front
        while (i < n && directions[i] == 'L') i++;

        // Skip cars moving right at the end → no one behind
        while (j >= 0 && directions[j] == 'R') j--;

        int collisions = 0;
        // All remaining L and R in the middle will collide
        for (int k = i; k <= j; k++) {
            if (directions[k] != 'S') collisions++;
        }
        return collisions;
    }
};