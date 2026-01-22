#include <vector>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        while (!isSorted(nums)) {
            int n = nums.size();
            int minSum = nums[0] + nums[1];
            int idx = 0;
            // find adjacent pair with minimum sum
            for (int i = 1; i + 1 < n; i++) {
                int sum = nums[i] + nums[i+1];
                if (sum < minSum) {
                    minSum = sum;
                    idx = i;
                }
            }
            // merge at idx
            nums[idx] = minSum;
            nums.erase(nums.begin() + idx + 1);
            ans++;
        }
        return ans;
    }

private:
    bool isSorted(const vector<int>& a) {
        for (int i = 1; i < (int)a.size(); i++)
            if (a[i-1] > a[i]) return false;
        return true;
    }
};