#include <vector>
#include <algorithm>
#include <numeric>  // for std::gcd
#include <climits>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;
        for (int x : nums) {
            if (x == 1) count1++;
        }
        // If there are already some 1's, we just need to convert all others in one operation each.
        if (count1 > 0) {
            return n - count1;
        }
        // Otherwise, need to create a 1 first by finding a subarray whose gcd is 1.
        int minLen = INT_MAX;
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i + 1; j < n; j++) {
                g = std::gcd(g, nums[j]);
                if (g == 1) {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }
        if (minLen == INT_MAX) {
            return -1;   // impossible to get a 1
        }
        // To create that first 1 takes (minLen - 1) operations, then to make all n elements become 1 takes (n - 1) operations.
        return (minLen - 1) + (n - 1);
    }
};