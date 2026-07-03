#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool isPossible(int minEdgeConstraint, int n, const vector<vector<pair<int, int>>>& adj, const vector<bool>& online, long long k) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> minCost(n, -1);

        pq.push({0, 0});
        minCost[0] = 0;

        while (!pq.empty()) {
            pair<long long, int> curr = pq.top();
            long long currentCost = curr.first;
            int u = curr.second;
            pq.pop();

            if (currentCost > minCost[u]) continue;
            if (u == n - 1) return true;

            for (size_t i = 0; i < adj[u].size(); ++i) {
                int v = adj[u][i].first;
                int weight = adj[u][i].second;

                if (weight < minEdgeConstraint) continue;
                if (v != n - 1 && !online[v]) continue;

                long long nextCost = currentCost + weight;
                if (nextCost <= k && (minCost[v] == -1 || nextCost < minCost[v])) {
                    minCost[v] = nextCost;
                    pq.push({nextCost, v});
                }
            }
        }
        return false;
    }

public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        int low = 0, high = 0;

        for (size_t i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            adj[u].push_back({v, weight});
            high = max(high, weight);
        }

        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(mid, n, adj, online, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution solver;
    vector<vector<int>> edges = {{0, 1, 5}, {1, 3, 10}, {0, 2, 3}, {2, 3, 4}};
    vector<bool> online = {true, true, true, true};
    long long k = 10;

    cout << solver.findMaxPathScore(edges, online, k) << endl;
    return 0;
}