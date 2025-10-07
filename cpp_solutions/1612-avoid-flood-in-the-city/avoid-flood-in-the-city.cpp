class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1); // initialize all with 1, will replace with -1 or lake number
        unordered_map<int, int> lake_to_day; // map of lake -> last day it was filled
        set<int> dry_days; // indices where we can dry a lake

        for (int i = 0; i < n; ++i) {
            if (rains[i] > 0) {
                int lake = rains[i];
                ans[i] = -1; // raining day, must be -1

                if (lake_to_day.count(lake)) {
                    int last_rain_day = lake_to_day[lake];
                    auto it = dry_days.upper_bound(last_rain_day); // find dry day after last rain

                    if (it == dry_days.end()) {
                        return {}; // no dry day to dry the lake => flood
                    }

                    ans[*it] = lake; // dry the lake on this dry day
                    dry_days.erase(it); // mark dry day as used
                }

                lake_to_day[lake] = i; // update last day lake was filled
            } else {
                dry_days.insert(i); // add this index as a potential dry day
                // ans[i] stays as 1 unless we assign a lake later
            }
        }
        return ans;
    }
};