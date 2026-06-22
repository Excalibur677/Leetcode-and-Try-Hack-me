#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> counts(26, 0);
        
        // Count frequencies of each letter
        for (char c : text) {
            counts[c - 'a']++;
        }
        
        // Extract counts for letters in "balloon"
        int bCount = counts['b' - 'a'];
        int aCount = counts['a' - 'a'];
        int lCount = counts['l' - 'a'] / 2; // Requires 2 letters per word
        int oCount = counts['o' - 'a'] / 2; // Requires 2 letters per word
        int nCount = counts['n' - 'a'];
        
        // The limiting character determines the maximum words formed
        return min({bCount, aCount, lCount, oCount, nCount});
    }
};

int main() {
    Solution solver;
    
    string text1 = "nlaebolko";
    cout << "Text: " << text1 << " -> Output: " << solver.maxNumberOfBalloons(text1) << endl; // Expected: 1
    
    string text2 = "loonbalxballpoon";
    cout << "Text: " << text2 << " -> Output: " << solver.maxNumberOfBalloons(text2) << endl; // Expected: 2
    
    return 0;
}