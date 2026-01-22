class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_set<char> mp;
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            while (mp.find(s[right]) != mp.end()) {
                mp.erase(s[left++]);
            }
            mp.insert(s[right]);
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};