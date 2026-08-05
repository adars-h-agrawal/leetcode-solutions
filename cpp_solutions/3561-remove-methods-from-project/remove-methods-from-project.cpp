class Solution {
public:
    void dfs(int u, vector<vector<int>>& g, vector<bool>& bad) {
        bad[u] = true;

        for (int v : g[u]) {
            if (!bad[v]) dfs(v, g, bad);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> g(n);

        for (auto &e : invocations) {
            g[e[0]].push_back(e[1]);
        }

        vector<bool> bad(n, false);

        // find all suspicious methods
        dfs(k, g, bad);

        // check if any outside node points inside
        for (auto &e: invocations) {
            int u = e[0];
            int v = e[1];

            if (!bad[u] && bad[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++) 
                    ans.push_back(i);
                return ans;
            }
        }

        // remove suspicious methods
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!bad[i]) ans.push_back(i);
        }
        return ans;
    }
};