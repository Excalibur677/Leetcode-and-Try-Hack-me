#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";
        
        for (const string& word : words) {
            long long totalWeight = 0;
            
            // 1. Sum up the weights of each character in the current word
            for (char ch : word) {
                totalWeight += weights[ch - 'a'];
            }
            
            // 2. Take total modulo 26
            int moduloIndex = totalWeight % 26;
            
            // 3. Map to reverse alphabetical order (0 -> 'z', 1 -> 'y', ..., 25 -> 'a')
            char mappedChar = 'z' - moduloIndex;
            
            // Append to the final resulting string
            result += mappedChar;
        }
        
        return result;
    }
};

int main() {
    Solution solver;
    
    // Example test case arrays
    vector<string> words = {"abcd", "def", "xyz"};
    vector<int> weights = {5, 3, 12, 14, 1, 2, 3, 2, 10, 6, 6, 9, 7, 8, 7, 10, 8, 9, 6, 9, 9, 8, 3, 7, 7, 2};
    
    string finalResult = solver.mapWordWeights(words, weights);
    cout << "Final Mapped Output String: " << finalResult << endl; // Expected output: "rij"
    
    return 0;
}