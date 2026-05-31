class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        int i = 0, n = asteroids.size();
        long long m = mass;
        while (i < n) {
            if (m < asteroids[i]) return false;
            m += asteroids[i++];
        }
        return true;
    }
};