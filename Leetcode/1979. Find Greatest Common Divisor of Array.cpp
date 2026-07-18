#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int gcd(int a, int b) {
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

public:
    int findGCD(vector<int>& nums) {
        int mn = nums[0];
        int mx = nums[0];
        
        for (int num : nums) {
            if (num < mn) mn = num;
            if (num > mx) mx = num;
        }
        
        return gcd(mn, mx);
    }
};

int main() {
    Solution solver;
    vector<int> nums = {2, 5, 6, 9, 10};
    cout << solver.findGCD(nums) << endl; // Expected: 2
    return 0;
}