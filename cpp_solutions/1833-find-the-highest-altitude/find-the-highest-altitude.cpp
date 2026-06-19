class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, alt = 0;
        for (int g : gain) {
            alt += g;
            ans = max(ans, alt);
        }
        return ans;
    }
};