class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {nums2[i], nums1[i]};
        }
        sort(a.rbegin(), a.rend()); // sort by nums2 descending

        priority_queue<int, vector<int>, greater<>> pq;
        long long sum = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            pq.push(a[i].second);
            sum += a[i].second;

            if (pq.size() > k) {
                sum -= pq.top(); pq.pop();
            }
            if (pq.size() == k) {
                ans = max(ans, sum * a[i].first);
            }
        }
        return ans;
    }
};