#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> ans;

        for (int length = 2; length <= 9; ++length) {
            for (int start = 0; start <= 9 - length; ++start) {
                string sub = digits.substr(start, length);
                int num = stoi(sub);
                
                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution solver;
    vector<int> result = solver.sequentialDigits(1000, 13000);
    
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl; // Expected: 1234 2345 3456 4567 5678 6789 12345
    return 0;
}