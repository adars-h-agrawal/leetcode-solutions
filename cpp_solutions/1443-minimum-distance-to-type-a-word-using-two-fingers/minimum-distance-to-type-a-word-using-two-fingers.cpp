// Use &1 trick to reduce space
class Solution {
public:
    static inline int dist(int x, int y) {
        if (x==26 || y==26) return 0;
        return abs(x/6-y/6)+abs(x%6-y%6);
    }

    static int minimumDistance(string word) {
        const int n=word.size();
        int dp[2][27];
        constexpr int INF=1e9+7;
        fill(dp[0], dp[0]+27, INF);

        //first character typed by finger1, finger2 hovering at 26
        dp[0][26]=0;
        int prev=word[0]-'A';

        for (int i=1; i<n; i++) {
            bool cur=i&1, prv=!cur;
            int x=word[i]-'A';

            fill(dp[cur], dp[cur]+27, INF);

            for (int j=0; j<27; j++) {
                if (dp[prv][j]>=INF) continue;

                // Move the finger 
                dp[cur][j]=min(dp[cur][j], dp[prv][j] + dist(prev, x));
                

                // Move the other finger 
                dp[cur][prev]=min(dp[cur][prev], dp[prv][j]+dist(j, x));

            }
            prev=x;
        }
        bool last=(n-1)&1;
        return *min_element(dp[last], dp[last]+27);
    }
};