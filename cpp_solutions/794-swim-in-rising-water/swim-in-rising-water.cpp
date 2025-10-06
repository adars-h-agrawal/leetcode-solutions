class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        // Directions: right, down, left, up
        const int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        // min‐heap storing (timeOrHeight, x, y)
        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        // start from (0,0)
        pq.emplace(grid[0][0], 0, 0);
        visited[0][0] = true;
        
        int ans = 0;
        
        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            pq.pop();
            
            // As we go, we need to wait until the water rises to max of seen heights
            ans = max(ans, h);
            
            // If reached bottom right, return
            if (x == n-1 && y == n-1) {
                return ans;
            }
            
            // Explore neighbors
            for (auto &d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (visited[nx][ny]) continue;
                visited[nx][ny] = true;
                // push the neighbor, with its terrain height
                pq.emplace(grid[nx][ny], nx, ny);
            }
        }
        
        // Should never reach here per problem constraints
        return -1;
    }
};