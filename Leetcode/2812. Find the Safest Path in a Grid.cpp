#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return 0;

        vector<vector<int>> distToThief(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    q.push({r, c});
                    distToThief[r][c] = 0;
                }
            }
        }

        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            int r = curr.first;
            int c = curr.second;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && distToThief[nr][nc] == -1) {
                    distToThief[nr][nc] = distToThief[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        priority_queue<vector<int>> pq; 
        pq.push({distToThief[0][0], 0, 0});

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;

        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();

            int safe = curr[0];
            int r = curr[1];
            int c = curr[2];

            if (r == n - 1 && c == n - 1) return safe;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    pq.push({min(safe, distToThief[nr][nc]), nr, nc});
                }
            }
        }

        return 0;
    }
};

int main() {
    Solution solver;
    vector<vector<int>> grid1 = {{0, 0, 1}, {0, 0, 0}, {0, 0, 0}};
    cout << "Test 1 Output: " << solver.maximumSafenessFactor(grid1) << " (Expected: 2)" << endl;
    return 0;
}