#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> comp(n, 0);
        int component_id = 0;

        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                component_id++;
            }
            comp[i] = component_id;
        }

        vector<bool> ans;
        ans.reserve(queries.size());
        for (const auto& q : queries) {
            ans.push_back(comp[q[0]] == comp[q[1]]);
        }

        return ans;
    }
};

int main() {
    Solution solver;
    vector<int> nums = {2, 5, 6, 8};
    vector<vector<int>> queries = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};
    
    vector<bool> result = solver.pathExistenceQueries(4, nums, 2, queries);
    for (bool val : result) {
        cout << (val ? "true" : "false") << " ";
    }
    cout << endl; 
    return 0;
}