#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool compareIntervals(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1]; 
        }
        return a[0] < b[0];     
    }

public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), compareIntervals);

        int remainingCount = intervals.size();
        int max_right = intervals[0][1];

        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][1] <= max_right) {
                remainingCount--;
            } else {
                max_right = intervals[i][1];
            }
        }

        return remainingCount;
    }
};

int main() {
    Solution solver;
    vector<vector<int>> intervals = {{1, 4}, {3, 6}, {2, 8}};
    cout << solver.removeCoveredIntervals(intervals) << endl; // Expected: 2
    return 0;
}