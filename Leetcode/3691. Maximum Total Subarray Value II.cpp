#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    int n;
    vector<int> maxTree, minTree;

    void buildTree(int node, int start, int end, const vector<int>& nums) {
        if (start == end) {
            maxTree[node] = nums[start];
            minTree[node] = nums[start];
            return;
        }
        int mid = start + (end - start) / 2;
        buildTree(2 * node, start, mid, nums);
        buildTree(2 * node + 1, mid + 1, end, nums);
        maxTree[node] = max(maxTree[2 * node], maxTree[2 * node + 1]);
        minTree[node] = min(minTree[2 * node], minTree[2 * node + 1]);
    }

    pair<int, int> queryTree(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return {INT_MIN, INT_MAX};
        }
        if (l <= start && end <= r) {
            return {maxTree[node], minTree[node]};
        }
        int mid = start + (end - start) / 2;
        auto leftQuery = queryTree(2 * node, start, mid, l, r);
        auto rightQuery = queryTree(2 * node + 1, mid + 1, end, l, r);
        return {max(leftQuery.first, rightQuery.first), min(leftQuery.second, rightQuery.second)};
    }

    // Helper structure to find the index of the maximum/minimum inside the segment tree range
    int findMaxIdx(int l, int r, const vector<int>& nums) {
        int target = queryTree(1, 0, n - 1, l, r).first;
        return lower_bound(nums.begin() + l, nums.begin() + r + 1, target) - nums.begin(); // Approximation helper
    }

    struct Element {
        long long val;
        int L;
        int rLeft;
        int rRight;
        int bestR;
        
        bool operator<(const Element& other) const {
            return val < other.val;
        }
    };

public:
    long long maxTotalValue(vector<int>& nums, int k) {
        n = nums.size();
        maxTree.resize(4 * n);
        minTree.resize(4 * n);
        buildTree(1, 0, n - 1, nums);

        priority_queue<Element> pq;

        for (int i = 0; i < n; i++) {
            auto q = queryTree(1, 0, n - 1, i, n - 1);
            long long maxVal = q.first - q.second;
            // For exact index tracking of the optimal R boundary, an index segment tree can be used.
            // Using a simplified variant mapping wide boundaries:
            pq.push({maxVal, i, i, n - 1, n - 1});
        }

        long long totalSum = 0;
        while (k-- > 0 && !pq.empty()) {
            Element curr = pq.top();
            pq.pop();
            
            totalSum += curr.val;

            if (curr.bestR > curr.rLeft) {
                int nextR = curr.bestR - 1;
                auto q = queryTree(1, 0, n - 1, curr.L, nextR);
                pq.push({(long long)q.first - q.second, curr.L, curr.rLeft, nextR, nextR});
            }
        }

        return totalSum;
    }
};

int main() {
    Solution solver;
    vector<int> nums = {4, 2, 5, 1};
    int k = 3;
    
    long long result = solver.maxTotalValue(nums, k);
    cout << "Maximum Total Subarray Value II: " << result << endl;
    
    return 0;
}