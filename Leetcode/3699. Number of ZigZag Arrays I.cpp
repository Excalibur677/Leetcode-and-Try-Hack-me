#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        long long MOD = 1e9 + 7;
        int m = r - l + 1;
        
        vector<long long> dp(m, 1);
        
        for (int i = 1; i < n; ++i) {
            vector<long long> next_dp(m, 0);
            long long running_sum = 0;
            
            if (i % 2 == 1) {
                for (int j = 0; j < m; ++j) {
                    next_dp[j] = running_sum;
                    running_sum = (running_sum + dp[j]) % MOD;
                }
            } else {
                for (int j = m - 1; j >= 0; --j) {
                    next_dp[j] = running_sum;
                    running_sum = (running_sum + dp[j]) % MOD;
                }
            }
            dp = move(next_dp);
        }
        
        long long total = 0;
        for (long long count : dp) {
            total = (total + count) % MOD;
        }
        
        return (total * 2) % MOD;
    }
};

int main() {
    Solution solver;
    cout << solver.zigZagArrays(3, 1, 3) << endl; 
    return 0;
}