#include <bits/stdc++.h>
using namespace std;

struct Packet {
    int source, dest, ts;
};

struct TripleHash {
    size_t operator()(const tuple<int,int,int>& t) const {
        auto [a,b,c] = t;
        // combine hashes
        size_t h1 = std::hash<int>()(a);
        size_t h2 = std::hash<int>()(b);
        size_t h3 = std::hash<int>()(c);
        // simple combine
        return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
};

class Router {
    int limit;
    deque<Packet> dq;
    unordered_set< tuple<int,int,int>, TripleHash > seen;
    // for each destination, sorted timestamps of active packets
    unordered_map<int, vector<int>> dst2ts;
public:
    Router(int memoryLimit) : limit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        auto tup = make_tuple(source, destination, timestamp);
        if (seen.count(tup)) return false;

        // if full, evict oldest
        if ((int)dq.size() == limit) {
            Packet &old = dq.front();
            auto old_tup = make_tuple(old.source, old.dest, old.ts);
            seen.erase(old_tup);

            // remove old.ts from dst2ts[old.dest]
            auto &vec = dst2ts[old.dest];
            // since vec is sorted and old.ts was inserted in non-decreasing order,
            // old.ts should be at front or close; use binary search to find
            auto it = lower_bound(vec.begin(), vec.end(), old.ts);
            if (it != vec.end() && *it == old.ts) {
                vec.erase(it);
            }
            // if vector becomes empty, optional: erase key to save space
            dq.pop_front();
        }

        // insert new packet
        dq.push_back(Packet{source, destination, timestamp});
        seen.insert(tup);

        auto &v = dst2ts[destination];
        v.push_back(timestamp);  // since timestamps non-decreasing, maintain sortedness

        return true;
    }

    vector<int> forwardPacket() {
        if (dq.empty()) return {};

        Packet old = dq.front();
        dq.pop_front();

        auto old_tup = make_tuple(old.source, old.dest, old.ts);
        seen.erase(old_tup);

        auto &vec = dst2ts[old.dest];
        auto it = lower_bound(vec.begin(), vec.end(), old.ts);
        if (it != vec.end() && *it == old.ts) {
            vec.erase(it);
        }

        return {old.source, old.dest, old.ts};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto itMap = dst2ts.find(destination);
        if (itMap == dst2ts.end()) return 0;
        auto &v = itMap->second;
        // find first >= startTime
        auto l = lower_bound(v.begin(), v.end(), startTime);
        // find first > endTime
        auto r = upper_bound(v.begin(), v.end(), endTime);
        return r - l;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */