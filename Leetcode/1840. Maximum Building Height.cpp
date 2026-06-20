#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());
        
        if (restrictions.back()[0] != n) {
            restrictions.push_back({n, n - 1});
        }
        
        int m = restrictions.size();
        
        for (int i = 1; i < m; ++i) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + (restrictions[i][0] - restrictions[i - 1][0]));
        }
        
        for (int i = m - 2; i >= 0; --i) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + (restrictions[i + 1][0] - restrictions[i][0]));
        }
        
        int maxHeight = 0;
        for (int i = 0; i < m - 1; ++i) {
            int id1 = restrictions[i][0], h1 = restrictions[i][1];
            int id2 = restrictions[i + 1][0], h2 = restrictions[i + 1][1];
            
            int peak = (h1 + h2 + (id2 - id1)) / 2;
            maxHeight = max(maxHeight, peak);
        }
        
        return maxHeight;
    }
};

int main() {
    Solution solver;
    vector<vector<int>> restrictions = {{3, 2}, {5, 3}};
    cout << solver.maxBuilding(5, restrictions) << endl; 
    return 0;
}