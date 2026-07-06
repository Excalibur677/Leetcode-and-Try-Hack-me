#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int deletions = 0;
        int b_count = 0;

        for (char c : s) {
            if (c == 'b') {
                b_count++;
            } else {
                deletions = min(deletions + 1, b_count);
            }
        }

        return deletions;
    }
};

int main() {
    Solution solver;
    string s = "aababbab";
    cout << solver.minimumDeletions(s) << endl; 
    return 0;
}