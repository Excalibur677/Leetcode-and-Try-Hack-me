#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string processStr(string s) {
        string result = "";
        
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                result.push_back(c);
            } 
            else if (c == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } 
            else if (c == '#') {
                if (!result.empty()) {
                    result += result; // Duplicate string content
                }
            } 
            else if (c == '%') {
                if (!result.empty()) {
                    reverse(result.begin(), result.end()); // Reverse in-place
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution solver;
    
    // Example 1
    string s1 = "a#b%*";
    cout << "Input: " << s1 << " -> Output: \"" << solver.processStr(s1) << "\"" << endl; // Expected: "ba"
    
    // Example 2
    string s2 = "z*#";
    cout << "Input: " << s2 << " -> Output: \"" << solver.processStr(s2) << "\"" << endl; // Expected: ""
    
    return 0;
}