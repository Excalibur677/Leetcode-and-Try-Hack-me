#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int globalMin = INT_MAX;
        int globalMax = INT_MIN;
        
        for (int num : nums) {
            globalMin = min(globalMin, num);
            globalMax = max(globalMax, num);
        }
        
        long long maxSubarrayValue = globalMax - globalMin;
        
        return maxSubarrayValue * k;
    }
};

int main() {
    Solution solver;
    vector<int> nums = {4, 2, 5, 1};
    int k = 3;
    
    long long result = solver.maxTotalValue(nums, k);
    cout << "Maximum Total Subarray Value: " << result << endl;
    
    return 0;
}