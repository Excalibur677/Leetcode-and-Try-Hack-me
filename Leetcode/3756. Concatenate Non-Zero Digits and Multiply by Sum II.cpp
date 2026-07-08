#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        static const int MX = 100001;
        static const int MOD = 1000000007;
        
        static vector<long long> pow10 = [] {
            vector<long long> p(MX);
            p[0] = 1;
            for (int i = 1; i < MX; i++) {
                p[i] = (p[i - 1] * 10) % MOD;
            }
            return p;
        }();

        int n = s.size();
        vector<int> sumD(n + 1, 0), cntN0(n + 1, 0);
        vector<long long> p(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int d = s[i - 1] - '0';
            sumD[i] = sumD[i - 1] + d;
            cntN0[i] = cntN0[i - 1] + (d > 0);
            p[i] = d ? (p[i - 1] * 10 + d) % MOD : p[i - 1];
        }

        vector<int> ans(queries.size());
        for (size_t i = 0; i < queries.size(); i++) {
            int l = queries[i][0], r = queries[i][1];
            int n0 = cntN0[r + 1] - cntN0[l];
            int sd = sumD[r + 1] - sumD[l];
            
            long long x = (p[r + 1] - p[l] * pow10[n0] % MOD + MOD) % MOD;
            ans[i] = (x * sd) % MOD;
        }

        return ans;
    }
};

int main() {
    Solution solver;
    string s = "10203004";
    vector<vector<int>> queries = {{0, 7}, {1, 3}, {4, 6}};
    
    vector<int> result = solver.sumAndMultiply(s, queries);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl; // Expected: 12340 4 9
    return 0;
}