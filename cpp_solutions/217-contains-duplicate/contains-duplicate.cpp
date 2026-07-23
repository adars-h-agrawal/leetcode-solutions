class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int n : nums) {
            if (freq[n] == 1)
                return true;
            freq[n]++;
        }
        return false;
    }
};