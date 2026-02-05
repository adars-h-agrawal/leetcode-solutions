class Solution {
public:
    void dfs(int i, vector<int>& visited, vector<vector<int>>& isConnected) {
        visited[i] = true;
        int n = isConnected.size();

        for (int j = 0; j < n; j++) {
            if (isConnected[i][j] == 1 && !visited[j]) {
                dfs(j, visited, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, visited, isConnected);
                count++;
            }
        }
        return count;
    }
};