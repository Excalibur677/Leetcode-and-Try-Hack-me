#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;

        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<int>> count(n, vector<int>(n, 0));

        dp[n - 1][n - 1] = 0;
        count[n - 1][n - 1] = 1;

        int dirs[3][2] = {{1, 0}, {0, 1}, {1, 1}};

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (board[i][j] == 'X' || (i == n - 1 && j == n - 1)) {
                    continue;
                }

                int max_score = -1;
                int path_count = 0;

                for (int d = 0; d < 3; ++d) {
                    int ni = i + dirs[d][0];
                    int nj = j + dirs[d][1];

                    if (ni < n && nj < n && dp[ni][nj] != -1) {
                        if (dp[ni][nj] > max_score) {
                            max_score = dp[ni][nj];
                            path_count = count[ni][nj];
                        } else if (dp[ni][nj] == max_score) {
                            path_count = (path_count + count[ni][nj]) % MOD;
                        }
                    }
                }

                if (max_score != -1) {
                    dp[i][j] = max_score;
                    if (board[i][j] != 'E') {
                        dp[i][j] += (board[i][j] - '0');
                    }
                    count[i][j] = path_count;
                }
            }
        }

        if (dp[0][0] == -1) {
            return {0, 0};
        }
        return {dp[0][0], count[0][0]};
    }
};

int main() {
    Solution solver;
    vector<string> board = {"E23", "2X2", "12S"};
    vector<int> result = solver.pathsWithMaxScore(board);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}