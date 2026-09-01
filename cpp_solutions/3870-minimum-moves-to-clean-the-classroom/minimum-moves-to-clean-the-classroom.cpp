class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        // id[i][j] = bit position of litter at (i,j)
        vector<vector<int>> id(m, vector<int>(n, -1));

        int sx = 0, sy = 0;
        int L = 0;

        // Find start and assign each litter a bit
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                else if (classroom[i][j] == 'L') {
                    id[i][j] = L++;
                }
            }
        }

        // No litter
        if (L == 0) return 0;

        int totalMasks = 1 << L;
        int fullMask = totalMasks - 1;

        /*
            State:
            (x, y, currentEnergy, mask)

            mask bit = 1 -> litter still needs to be collected
            mask bit = 0 -> litter already collected
        */

        vector<vector<vector<vector<bool>>>> vis(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(totalMasks, false)
                )
            )
        );

        queue<tuple<int, int, int, int>> q;

        q.push({sx, sy, energy, fullMask});
        vis[sx][sy][energy][fullMask] = true;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [x, y, curEnergy, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == 0)
                    return moves;

                // Cannot move with 0 energy
                if (curEnergy == 0)
                    continue;

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    // Outside grid / obstacle
                    if (nx < 0 || nx >= m ||
                        ny < 0 || ny >= n ||
                        classroom[nx][ny] == 'X') {
                        continue;
                    }

                    // Every normal move costs 1 energy.
                    int nextEnergy = curEnergy - 1;

                    // R restores energy AFTER entering it.
                    if (classroom[nx][ny] == 'R') {
                        nextEnergy = energy;
                    }

                    int nextMask = mask;

                    // Collect litter
                    if (classroom[nx][ny] == 'L') {
                        nextMask &= ~(1 << id[nx][ny]);
                    }

                    if (!vis[nx][ny][nextEnergy][nextMask]) {
                        vis[nx][ny][nextEnergy][nextMask] = true;

                        q.push({
                            nx,
                            ny,
                            nextEnergy,
                            nextMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};
