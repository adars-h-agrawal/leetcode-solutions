class Solution {
public:
    void dfs(int room, vector<bool>& visited, vector<vector<int>>& rooms) {
        visited[room] = true;
        for (int key : rooms[room]) {
            if (!visited[key]) dfs(key, visited, rooms);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        dfs(0, visited, rooms);

        for (bool wasVisited : visited) {
            if (!wasVisited) return false;
        }
        return true;
    }
};