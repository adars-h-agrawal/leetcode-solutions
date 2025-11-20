class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Sort by end asc, start desc
        sort(intervals.begin(), intervals.end(), [](auto &x, auto &y){
            if (x[1] == y[1]) return x[0] > y[0];
            return x[1] < y[1];
        });

        int a = -1, b = -1; // last two chosen points
        int res = 0;

        for (auto &it : intervals) {
            int l = it[0], r = it[1];

            // Case 1: interval already covered by a,b
            if (l <= b) continue;

            // Case 2: interval contains a but not b → pick one more
            if (l <= a) {
                res += 1;
                b = a;          // shift
                a = r;          // add one new point
            }
            // Case 3: contains none → pick two
            else {
                res += 2;
                b = r - 1;
                a = r;
            }
        }
        return res;
    }
};