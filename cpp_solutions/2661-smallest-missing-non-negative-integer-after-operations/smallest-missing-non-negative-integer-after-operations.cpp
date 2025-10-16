#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> cnt;
        cnt.reserve(nums.size());
        cnt.max_load_factor(0.7);
        
        // Count how many numbers fall into each remainder class mod value
        for (int x : nums) {
            int r = ((x % value) + value) % value;
            cnt[r]++;
        }
        
        // Try to form 0, 1, 2, … in order
        for (int i = 0; ; i++) {
            int r = i % value;
            auto it = cnt.find(r);
            if (it == cnt.end() || it->second == 0) {
                // We can't form i, so it is the MEX
                return i;
            }
            it->second--;
        }
        
        // unreachable
        return -1;
    }
};