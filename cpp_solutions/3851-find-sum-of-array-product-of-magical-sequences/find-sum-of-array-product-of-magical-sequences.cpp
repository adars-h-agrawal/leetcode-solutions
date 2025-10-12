class Solution {
public:
    static constexpr int MOD = 1'000'000'007;

    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();
        // Precompute combinations C(n, r) up to n = m
        vector<vector<long long>> comb(m+1, vector<long long>(m+1, 0));
        for (int i = 0; i <= m; i++) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
            }
        }

        // mem[m_left][k_left][i][carry] = result (or -1 if not computed)
        // But full 4D might be too big. Use map or compress? Here using vector with sentinel.
        // Max values: m ≤ 30, k ≤ m, i ≤ n ≤ 50, carry up to m
        static int dp_mem[31][31][51][31];
        // initialize to -1
        for (int mm = 0; mm <= m; mm++)
            for (int kk = 0; kk <= m; kk++)
                for (int i = 0; i <= n; i++)
                    for (int c = 0; c <= m; c++)
                        dp_mem[mm][kk][i][c] = -1;

        function<int(int,int,int,int)> dfs = [&](int mm, int kk, int i, int carry) -> int {
            if (mm < 0 || kk < 0) return 0;
            // if even with all remaining bits we can’t reach k bits
            if (mm + __builtin_popcount(carry) < kk) return 0;
            if (mm == 0) {
                return (kk == __builtin_popcount(carry)) ? 1 : 0;
            }
            if (i == n) return 0;
            int &res = dp_mem[mm][kk][i][carry];
            if (res != -1) return res;
            long long ans = 0;
            // try selecting nums[i] count times (0 to mm)
            for (int cnt = 0; cnt <= mm; cnt++) {
                long long contrib = comb[mm][cnt] * modPow(nums[i], cnt) % MOD;
                int newCarry = carry + cnt;
                int nextK = kk - (newCarry % 2);
                int nextCarry = newCarry / 2;
                long long sub = dfs(mm - cnt, nextK, i + 1, nextCarry);
                ans = (ans + contrib * sub) % MOD;
            }
            return res = (int)ans;
        };

        return dfs(m, k, 0, 0);
    }

private:
    long long modPow(long long x, int e) {
        long long res = 1;
        x %= MOD;
        while (e > 0) {
            if (e & 1) res = (res * x) % MOD;
            x = (x * x) % MOD;
            e >>= 1;
        }
        return res;
    }
};