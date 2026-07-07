#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    long long sumAndMultiply(long long n) {
        string s = to_string(n);
        string non_zero_str = "";
        long long digit_sum = 0;

        for (char c : s) {
            if (c != '0') {
                non_zero_str += c;
                digit_sum += (c - '0');
            }
        }

        if (non_zero_str.empty()) return 0;

        long long x = stoll(non_zero_str);
        return x * digit_sum;
    }
};

int main() {
    Solution solver;
    long long n = 10203004;
    cout << solver.sumAndMultiply(n) << endl; 
    return 0;
}