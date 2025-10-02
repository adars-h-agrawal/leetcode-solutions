class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> stk;

        for (int num : nums) {
            stk.push_back(num);
            while (stk.size() >= 2) {
                int b = stk.back(); stk.pop_back();
                int a = stk.back(); stk.pop_back();
                int g = gcd(a, b);
                if (g == 1) {
                    stk.push_back(a);
                    stk.push_back(b);
                    break;
                } else {
                    stk.push_back(lcm(a, b));
                }
            }
        }

        return stk;
    }

private:
    // C++17 or later required for std::lcm
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};