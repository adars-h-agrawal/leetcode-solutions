class Solution {
public:
    vector<int> parent, rankv;
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        if (rankv[px] < rankv[py])
            parent[px] = py;
        else if (rankv[px] > rankv[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rankv[px]++;
        }
    }
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        parent.resize(n);
        rankv.assign(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        // Person 0 shares secret with firstPerson at time 0
        unite(0, firstPerson);
        
        // Sort meetings by time
        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) { return a[2] < b[2]; });
        
        int i = 0;
        while (i < meetings.size()) {
            int time = meetings[i][2];
            vector<int> people;
            
            // Process all meetings at the same time
            while (i < meetings.size() && meetings[i][2] == time) {
                unite(meetings[i][0], meetings[i][1]);
                people.push_back(meetings[i][0]);
                people.push_back(meetings[i][1]);
                i++;
            }
            
            // Reset connections for those not connected to person 0
            for (int p : people) {
                if (find(p) != find(0))
                    parent[p] = p;
            }
        }
        
        // Collect all who know the secret
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (find(i) == find(0))
                result.push_back(i);
        }
        return result;
    }
};