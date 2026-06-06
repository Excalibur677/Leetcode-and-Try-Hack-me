#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        
        int rightSum = 0;
        for (int num : nums) {
            rightSum += num;
        }
        
        int leftSum = 0;
        
        for (int i = 0; i < n; i++) {
            rightSum -= nums[i];
            answer[i] = abs(leftSum - rightSum);
            leftSum += nums[i];
        }
        
        return answer;
    }
};

int main() {
    Solution solver;
    vector<int> nums = {10, 4, 8, 3};
    
    vector<int> result = solver.leftRightDifference(nums);
    
    cout << "Result Array: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}