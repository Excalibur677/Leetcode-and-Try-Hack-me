#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto [mn, mx] = minmax_element(nums.begin(), nums.end());
        return gcd(*mn, *mx);
    }
};

int main() {
    Solution solver;
    vector<int> nums = {2, 5, 6, 9, 10};
    cout << solver.findGCD(nums) << endl; // Expected: 2 (gcd of 2 and 10)
    return 0;
}