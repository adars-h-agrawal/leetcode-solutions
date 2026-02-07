class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = spells.size(), n = potions.size();
        vector<int> ans(m);

        for (int i = 0; i < m; i++) {
            int left = 0, right = n-1, cur = 0;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (1LL * spells[i] * potions[mid] < success) left = mid + 1;
                else {
                    cur = n - mid;
                    right = mid - 1;
                }
            }
            ans[i] = cur;
        }
        return ans;
    }
};