#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        arr[0] = 1;
        for (size_t i = 1; i < arr.size(); ++i) {
            arr[i] = min(arr[i], arr[i - 1] + 1);
        }
        
        return arr.back();
    }
};

int main() {
    Solution solver;
    
    vector<int> arr1 = {2, 2, 1, 2, 1};
    cout << "Test 1 Output: " << solver.maximumElementAfterDecrementingAndRearranging(arr1) << " (Expected: 2)" << endl;
    
    vector<int> arr2 = {100, 1, 1000};
    cout << "Test 2 Output: " << solver.maximumElementAfterDecrementingAndRearranging(arr2) << " (Expected: 3)" << endl;
    
    return 0;
}