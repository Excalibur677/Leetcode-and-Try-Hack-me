#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n);
        
        int lessElements = 0;
        int equalElements = 0;
        
        for (int num : nums) {
            if (num < pivot) {
                lessElements++;
            } else if (num == pivot) {
                equalElements++;
            }
        }
        
        int lessIdx = 0;
        int equalIdx = lessElements;
        int greaterIdx = lessElements + equalElements;
        
        for (int num : nums) {
            if (num < pivot) {
                result[lessIdx++] = num;
            } else if (num == pivot) {
                result[equalIdx++] = num;
            } else {
                result[greaterIdx++] = num;
            }
        }
        
        return result;
    }
};

int main() {
    Solution solver;
    vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
    int pivot = 10;
    
    vector<int> result = solver.pivotArray(nums, pivot);
    
    cout << "Partitioned Array: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}