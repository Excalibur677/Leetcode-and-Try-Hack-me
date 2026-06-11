#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int maxDepth = 0;

    void dfs(int node, int parent, int currentDepth, const vector<vector<int>>& adj) {
        maxDepth = max(maxDepth, currentDepth);
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, currentDepth + 1, adj);
            }
        }
    }

    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        maxDepth = 0;
        dfs(1, -1, 0, adj);

        if (maxDepth == 0) return 0;

        long long MOD = 1000000007;
        return power(2, maxDepth - 1, MOD);
    }
};

int main() {
    Solution solver;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {3, 4}, {3, 5}};
    
    int result = solver.assignEdgeWeights(edges);
    cout << "Number of Valid Assignments: " << result << endl;
    
    return 0;
}