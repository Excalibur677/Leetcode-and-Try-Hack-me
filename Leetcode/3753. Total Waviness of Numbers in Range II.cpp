#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long dp[20][11][11][2][2];

class Solution {
private:
    long long solve(int idx, int prev, int prev_prev, bool is_less, bool is_started, const string& num) {
        if (idx == num.length()) {
            return 0;
        }

        if (dp[idx][prev + 1][prev_prev + 1][is_less][is_started] != -1) {
            return dp[idx][prev + 1][prev_prev + 1][is_less][is_started];
        }

        int limit = is_less ? 9 : (num[idx] - '0');
        long long total_waviness = 0;

        for (int digit = 0; digit <= limit; digit++) {
            bool next_less = is_less || (digit < limit);
            bool next_started = is_started || (digit > 0);

            long long current_waviness = 0;
            if (is_started && prev != -1 && prev_prev != -1) {
                if ((prev > prev_prev && prev > digit) || (prev < prev_prev && prev < digit)) {
                    current_waviness = 1;
                }
            }

            if (next_started) {
                long long ways_ahead = 0;
                if (idx + 1 == num.length()) ways_ahead = 1; 
                else {
                    long long temp = 0;
                    for (int nxt = 0; nxt <= 9; nxt++) temp += 1; 
                    ways_ahead = 1; 
                }
                
                total_waviness += current_waviness * countWays(idx + 1, next_less, next_started, num) + 
                                  solve(idx + 1, digit, prev, next_less, next_started, num);
            } else {
                total_waviness += solve(idx + 1, -1, -1, next_less, false, num);
            }
        }

        return dp[idx][prev + 1][prev_prev + 1][is_less][is_started] = total_waviness;
    }

    long long countWays(int idx, bool is_less, bool is_started, const string& num) {
        if (idx == num.length()) return 1;
        int limit = is_less ? 9 : (num[idx] - '0');
        long long ways = 0;
        for (int digit = 0; digit <= limit; digit++) {
            ways += countWays(idx + 1, is_less || (digit < limit), is_started || (digit > 0), num);
        }
        return ways;
    }

    long long getWavinessSum(long long n) {
        if (n < 100) return 0;
        string num = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, -1, false, false, num);
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return getWavinessSum(num2) - getWavinessSum(num1 - 1);
    }
};

int main() {
    Solution solver;
    long long num1 = 120, num2 = 130;
    cout << "Total Waviness: " << solver.totalWaviness(num1, num2) << endl;
    return 0;
}