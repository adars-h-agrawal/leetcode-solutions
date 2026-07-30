class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();

        for (int cur = n; cur > 1; cur--) {
            int maxIdx = 0;
            for (int i = 0; i < cur; i++) {
                if (arr[i] > arr[maxIdx]) maxIdx = i;
            }

            // already in correct pos
            if (maxIdx == cur - 1) continue;

            // bring to front
            if (maxIdx != 0) {
                reverse(arr.begin(), arr.begin() + maxIdx + 1);
                ans.push_back(maxIdx + 1);
            }

            // move cur max to correct pos
            reverse(arr.begin(), arr.begin() + cur);
            ans.push_back(cur);
        }
        return ans;
    }
};