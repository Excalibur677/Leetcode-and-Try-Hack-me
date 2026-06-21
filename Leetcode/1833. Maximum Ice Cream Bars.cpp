#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;
        
        for (int cost : costs) {
            if (coins >= cost) {
                coins -= cost;
                count++;
            } else {
                break;
            }
        }
        
        return count;
    }
};

int main() {
    Solution solver;
    vector<int> costs = {1, 3, 2, 4, 1};
    int coins = 7;
    
    cout << solver.maxIceCream(costs, coins) << endl; // Expected Output: 4
    return 0;
}