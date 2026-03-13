class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;

        for (int a : asteroids) {
            bool alive = true;
            while (!ans.empty() && ans.back() > 0 && a < 0) {
                if (ans.back() > -a) { // new explodes
                    alive = false;
                    break;
                } else if (ans.back() == -a) { // both explode
                    ans.pop_back();
                    alive = false;
                    break;
                } else {
                    ans.pop_back(); // top explodes
                }
            }
            if (alive) ans.push_back(a);
        }
        return ans;
    }
};