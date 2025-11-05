#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        using pii = pair<int,int>; // (count, value)
        unordered_map<int,int> cnt;
        multiset<pii> top, bot; 
        long long windowSum = 0;
        vector<long long> ans;
        int n = nums.size();

        auto update = [&](int v, int delta) {
            int old = cnt[v];
            if (old > 0) {
                // remove the old (old, v) from one of the sets
                pii p = {old, v};
                auto it_bot = bot.find(p);
                if (it_bot != bot.end()) {
                    bot.erase(it_bot);
                } else {
                    auto it_top = top.find(p);
                    if (it_top != top.end()) {
                        top.erase(it_top);
                        windowSum -= (long long) p.first * p.second;
                    }
                }
            }
            cnt[v] = old + delta;
            int now = cnt[v];
            if (now > 0) {
                bot.insert({now, v});
            } else {
                cnt.erase(v);
            }
        };

        for (int i = 0; i < n; ++i) {
            update(nums[i], +1);
            if (i >= k) {
                update(nums[i - k], -1);
            }
            // ensure top has exactly x largest (by count, then by value)
            while (!bot.empty() && (int)top.size() < x) {
                auto it = prev(bot.end());
                pii p = *it;
                bot.erase(it);
                top.insert(p);
                windowSum += (long long)p.first * p.second;
            }
            while (!bot.empty() && !top.empty() && *prev(bot.end()) > *top.begin()) {
                // swap an element between bot (largest) and top (smallest)
                pii pB = *prev(bot.end());
                pii pT = *top.begin();
                bot.erase(prev(bot.end()));
                top.erase(top.begin());
                bot.insert(pT);
                top.insert(pB);
                windowSum += (long long)pB.first * pB.second;
                windowSum -= (long long)pT.first * pT.second;
            }
            if (i >= k - 1) {
                ans.push_back(windowSum);
            }
        }

        return ans;
    }
};