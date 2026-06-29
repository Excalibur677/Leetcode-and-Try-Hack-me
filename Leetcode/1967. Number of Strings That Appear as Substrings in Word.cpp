#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (const string& pattern : patterns) {
            if (word.find(pattern) != string::npos) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution solver;
    
    vector<string> patterns1 = {"a", "abc", "bc", "d"};
    string word1 = "abc";
    cout << "Test 1 Output: " << solver.numOfStrings(patterns1, word1) << " (Expected: 3)" << endl;
    
    vector<string> patterns2 = {"a", "b", "c"};
    string word2 = "aaaaabbbbb";
    cout << "Test 2 Output: " << solver.numOfStrings(patterns2, word2) << " (Expected: 2)" << endl;
    
    return 0;
}