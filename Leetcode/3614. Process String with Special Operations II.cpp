#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    char scarcityOfOperations(string s, long long k) {
        int n = s.length();
        vector<long long> lengths(n);
        long long current_len = 0;

        // Step 1: Compute the length of the string at each operation index
        for (int i = 0; i < n; ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                current_len++;
            } else if (s[i] == '*') {
                if (current_len > 0) current_len--;
            } else if (s[i] == '#') {
                current_len *= 2;
            } else if (s[i] == '%') {
                // Length doesn't change on inversion
            }
            lengths[i] = current_len;
        }

        // If k is completely out of the final string's boundary bounds
        if (k >= current_len) {
            return '.';
        }

        // Step 2: Reverse engineer the position of k from back to front
        for (int i = n - 1; i >= 0; --i) {
            if (lengths[i] == 0) continue;

            if (s[i] >= 'a' && s[i] <= 'z') {
                // If k is pointing to the character that was just appended at this step
                if (k == lengths[i] - 1) {
                    return s[i];
                }
            } 
            else if (s[i] == '#') {
                long long half_len = lengths[i] / 2;
                if (k >= half_len) {
                    k -= half_len; // Map k back into the original first half
                }
            } 
            else if (s[i] == '%') {
                k = lengths[i] - 1 - k; // Invert k back to its pre-reversed position
            }
            // Note: For '*', the prior length is naturally captured by lengths[i-1]
        }

        return '.';
    }
};

int main() {
    Solution solver;
    
    // Sample Test Case
    string s = "a#b%";
    long long k = 1; 
    // Explanation: 'a' -> "a" -> '#' -> "aa" -> 'b' -> "aab" -> '%' -> "baa"
    // Index 1 of "baa" is 'a'
    
    cout << "Character at index " << k << " is: " << solver.scarcityOfOperations(s, k) << endl; // Expected: a
    return 0;
}