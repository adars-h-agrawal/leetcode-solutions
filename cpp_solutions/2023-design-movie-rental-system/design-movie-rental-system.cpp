#include <bits/stdc++.h>
using namespace std;

struct MovieRentingSystem {
    unordered_map<long long, int> priceMap;
    unordered_map<int, set<pair<int,int>>> available;
    set<tuple<int,int,int>> rented;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e: entries) {
            int shop = e[0], movie = e[1], price = e[2];
            long long key = ((long long)shop << 32) | movie;
            priceMap[key] = price;
            available[movie].emplace(price, shop);
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        auto &s = available[movie];
        for (auto it = s.begin(); it != s.end() && res.size() < 5; ++it) {
            res.push_back(it->second);
        }
        return res;
    }

    void rent(int shop, int movie) {
        long long key = ((long long)shop << 32) | movie;
        int price = priceMap[key];
        available[movie].erase({price, shop});
        rented.emplace(price, shop, movie);
    }

    void drop(int shop, int movie) {
        long long key = ((long long)shop << 32) | movie;
        int price = priceMap[key];
        rented.erase({price, shop, movie});
        available[movie].emplace(price, shop);
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        for (auto it = rented.begin(); it != rented.end() && res.size() < 5; ++it) {
            auto &[price, shop, movie] = *it;
            res.push_back({shop, movie});
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */