#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        deque<pair<int, int>> dq;
        
        dist[0][0] = grid[0][0];
        dq.push_back({0, 0});
        
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!dq.empty()) {
            pair<int, int> curr = dq.front();
            int r = curr.first;
            int c = curr.second;
            dq.pop_front();
            
            if (r == m - 1 && c == n - 1) {
                break;
            }
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int weight = grid[nr][nc];
                    if (dist[r][c] + weight < dist[nr][nc]) {
                        dist[nr][nc] = dist[r][c] + weight;
                        if (weight == 0) {
                            dq.push_front({nr, nc});
                        } else {
                            dq.push_back({nr, nc});
                        }
                    }
                }
            }
        }
        
        return dist[m - 1][n - 1] < health;
    }
};

int main() {
    Solution solver;
    vector<vector<int>> grid = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0}
    };
    int health = 1;
    cout << "Test Output: " << (solver.findSafeWalk(grid, health) ? "true" : "false") << " (Expected: true)" << endl;
    return 0;
}