#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long totalSubarrays = 0;
        
        for (int i = 0; i < n; ++i) {
            int balanceScore = 0;
            for (int j = i; j < n; ++j) {
                if (nums[j] == target) {
                    balanceScore += 1;
                } else {
                    balanceScore -= 1;
                }
                
                if (balanceScore > 0) {
                    totalSubarrays++;
                }
            }
        }
        
        return totalSubarrays;
    }
};

int main() {
    Solution solver;
    vector<int> nums = {1, 2, 2, 3};
    int target = 2;
    cout << solver.countMajoritySubarrays(nums, target) << endl; 
    return 0;
}