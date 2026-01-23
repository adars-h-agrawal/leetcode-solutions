class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        for (int a : asteroids) {
            bool alive = true;
            while (!stack.empty() && (stack.back() > 0 && a < 0)) {
                if (stack.back() < -a) {
                    stack.pop_back(); // top explodes
                } else if (stack.back() == -a) {
                    stack.pop_back(); // both explodes
                    alive = false;
                    break;
                } else {
                    alive = false; // curr explodes
                    break;
                }
            }
            if (alive) stack.push_back(a);
        }
        return stack;
    }
};