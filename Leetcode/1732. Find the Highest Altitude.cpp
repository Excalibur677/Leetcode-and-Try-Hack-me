#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0;
        int currentAltitude = 0;
        
        for (int g : gain) {
            currentAltitude += g; 
            maxAltitude = max(maxAltitude, currentAltitude); 
        }
        
        return maxAltitude;
    }
};

int main() {
    Solution solver;
    

    vector<int> gain1 = {-5, 1, 5, 0, -7};
    cout << "Highest Altitude: " << solver.largestAltitude(gain1) << endl; 
    

    vector<int> gain2 = {4, -3, 2, 2, -10};
    cout << "Highest Altitude: " << solver.largestAltitude(gain2) << endl; 
    
    return 0;
}