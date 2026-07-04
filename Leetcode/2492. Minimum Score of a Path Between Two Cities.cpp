#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        int ans = INT_MAX;
        vector<bool> visited(n + 1, false);
        queue<int> q;

        q.push(1);
        visited[1] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                ans = min(ans, weight);

                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution solver;
    vector<vector<int>> roads = {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}};
    cout << solver.minScore(4, roads) << endl;
    return 0;
}