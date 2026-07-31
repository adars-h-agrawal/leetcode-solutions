class Solution {
public:
    int minimumPushes(string word) {
        vector<int> frq(26, 0);

        for (char c : word) {
            frq[c - 'a']++;
        }
        sort(frq.begin(), frq.end(), greater<int>());

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += (i / 8 + 1) * frq[i];
        }

        return ans;
    }
};