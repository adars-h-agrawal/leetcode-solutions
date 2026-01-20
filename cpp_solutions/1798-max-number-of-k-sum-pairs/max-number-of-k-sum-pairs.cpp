class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;
        for (int num : nums) {
            if (mp.find(k - num) != mp.end()) {
                ans++;
                mp[k - num]--;
                if (mp[k - num] == 0) mp.erase(k - num);
            } else {
                mp[num]++;
            } 
        }
        return ans;
    }
};