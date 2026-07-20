#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        k = k % total;
        
        vector<vector<int>> ans(m, vector<int>(n));
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int oldIdx = r * n + c;
                int newIdx = (oldIdx + k) % total;
                ans[newIdx / n][newIdx % n] = grid[r][c];
            }
        }
        
        return ans;
    }
};

int main() {
    Solution solver;
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k = 1;
    
    vector<vector<int>> result = solver.shiftGrid(grid, k);
    
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
    // Expected output:
    // 9 1 2 
    // 3 4 5 
    // 6 7 8 
    return 0;
}