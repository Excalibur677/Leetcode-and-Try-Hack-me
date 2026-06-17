#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
private:
    static constexpr int MOD = 1000000007;
    static constexpr int LOG = 17; // 2^17 > 10^5
    
    long long modPow(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    void dfs(int u, int p, const vector<vector<int>>& graph, vector<vector<int>>& parent, vector<int>& depth) {
        parent[0][u] = p;
        for (int v : graph[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u, graph, parent, depth);
            }
        }
    }

    int lca(int u, int v, const vector<vector<int>>& parent, const vector<int>& depth) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int k = LOG - 1; k >= 0; --k) {
            if (depth[u] - (1 << k) >= depth[v]) {
                u = parent[k][u];
            }
        }
        if (u == v) return u;
        for (int k = LOG - 1; k >= 0; --k) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        vector<vector<int>> graph(n + 1);
        vector<vector<int>> parent(LOG, vector<int>(n + 1, -1));
        vector<int> depth(n + 1, 0);

        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        dfs(1, -1, graph, parent, depth);

        for (int k = 1; k < LOG; ++k) {
            for (int v = 1; v <= n; ++v) {
                if (parent[k - 1][v] != -1) {
                    parent[k][v] = parent[k - 1][parent[k - 1][v]];
                }
            }
        }

        vector<int> ans;
        for (const auto& q : queries) {
            int u = q[0], v = q[1];
            if (u == v) {
                ans.push_back(0);
            } else {
                int a = lca(u, v, parent, depth);
                int d = depth[u] + depth[v] - 2 * depth[a];
                ans.push_back(modPow(2, d - 1));
            }
        }
        return ans;
    }
};

int main() {
    Solution solver;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {3, 4}, {3, 5}};
    vector<vector<int>> queries = {{1, 4}, {3, 4}, {2, 5}};
    
    vector<int> result = solver.assignEdgeWeights(edges, queries);
    
    
    cout << "Results: ";
    for (int val : result) cout << val << " ";
    cout << endl;
    
    return 0;
}