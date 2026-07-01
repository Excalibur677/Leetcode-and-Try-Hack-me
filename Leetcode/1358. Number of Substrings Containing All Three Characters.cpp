#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int last_a = -1, last_b = -1, last_c = -1;
        int count = 0;
        int n = s.length();

        for (int r = 0; r < n; ++r) {
            if (s[r] == 'a') last_a = r;
            else if (s[r] == 'b') last_b = r;
            else if (s[r] == 'c') last_c = r;

            // If we have seen all three characters at least once
            if (last_a != -1 && last_b != -1 && last_c != -1) {
                int min_idx = min(last_a, min(last_b, last_c));
                count += min_idx + 1;
            }
        }

        return count;
    }
};

int main() {
    Solution solver;
    
    string s1 = "abcabc";
    cout << "Test 1 Output: " << solver.numberOfSubstrings(s1) << " (Expected: 10)" << endl;
    
    string s2 = "aaacb";
    cout << "Test 2 Output: " << solver.numberOfSubstrings(s2) << " (Expected: 3)" << endl;
    
    return 0;
}
