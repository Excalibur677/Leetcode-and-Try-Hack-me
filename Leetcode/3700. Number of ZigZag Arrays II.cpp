#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
private:
    long long MOD = 1e9 + 7;

    vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
        int sz = A.size();
        vector<vector<long long>> C(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; ++i) {
            for (int k = 0; k < sz; ++k) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < sz; ++j) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    vector<vector<long long>> power(vector<vector<long long>> A, long long p) {
        int sz = A.size();
        vector<vector<long long>> res(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; ++i) res[i][i] = 1;
        while (p > 0) {
            if (p & 1) res = multiply(res, A);
            A = multiply(A, A);
            p >>= 1;
        }
        return res;
    }

public:
    int zigZagArrays(long long n, int l, int r) {
        int k = r - l + 1;
        if (k <= 1) return 0;
        int sz = 2 * k;

        vector<vector<long long>> T(sz, vector<long long>(sz, 0));

        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                if (i < j) T[j][i] = 1;
                if (i > j) T[k + j][k + i] = 1;
            }
        }

        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                if (i > j) T[k + j][i] = 1;
                if (i < j) T[j][k + i] = 1;
            }
        }

        T = power(T, n - 2);

        long long total = 0;
        vector<long long> initial(sz, 0);

        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                if (i < j) initial[j]++;
                if (i > j) initial[k + j]++;
            }
        }

        for (int i = 0; i < sz; ++i) {
            long long components = 0;
            for (int j = 0; j < sz; ++j) {
                components = (components + T[i][j] * initial[j]) % MOD;
            }
            total = (total + components) % MOD;
        }

        return total;
    }
};

int main() {
    Solution solver;
    cout << solver.zigZagArrays(3, 1, 3) << endl; 
    return 0;
}