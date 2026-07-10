#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> sorted_nums(n);
        for (int i = 0; i < n; ++i) {
            sorted_nums[i] = {nums[i], i};
        }
        sort(sorted_nums.begin(), sorted_nums.end());

        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[sorted_nums[i].second] = i;
        }

        int LOG = 18;
        vector<vector<int>> st(n, vector<int>(LOG, 0));

        int r = 0;
        for (int l = 0; l < n; ++l) {
            while (r < n && sorted_nums[r].first - sorted_nums[l].first <= maxDiff) {
                r++;
            }
            st[l][0] = r - 1;
        }

        for (int j = 1; j < LOG; ++j) {
            for (int i = 0; i < n; ++i) {
                st[i][j] = st[st[i][j - 1]][j - 1];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];
            if (u > v) swap(u, v);

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int steps = 0;
            int curr = u;

            for (int j = LOG - 1; j >= 0; --j) {
                if (st[curr][j] < v) {
                    curr = st[curr][j];
                    steps += (1 << j);
                }
            }

            if (st[curr][0] >= v) {
                ans.push_back(steps + 1);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};

int main() {
    Solution solver;
    vector<int> nums = {1, 8, 3, 4, 2};
    vector<vector<int>> queries = {{0, 3}, {2, 4}};
    
    vector<int> result = solver.pathExistenceQueries(5, nums, 3, queries);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl; // Expected: 1 1
    return 0;
}