class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        sort(potions.begin(), potions.end());
        vector<int> result(n, 0);

        for (int i = 0; i < n; i++) {
            int left = 0, right = potions.size() - 1;
            int ans = 0;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if ((long long)spells[i] * potions[mid] < success) left = mid + 1;
                else {
                    ans = potions.size() - mid;
                    right = mid - 1;
                }
            }
            result[i] = ans;
        }
        return result;
    }
};