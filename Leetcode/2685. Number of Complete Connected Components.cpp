#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int completeComponents = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int vertexCount = 0;
                int totalEdges = 0;
                queue<int> q;

                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    vertexCount++;
                    totalEdges += adj[u].size();

                    for (int v : adj[u]) {
                        if (!visited[v]) {
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }

                if (totalEdges == vertexCount * (vertexCount - 1)) {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }
};

int main() {
    Solution solver;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};
    cout << solver.countCompleteComponents(6, edges) << endl; // Expected: 3
    return 0;
}