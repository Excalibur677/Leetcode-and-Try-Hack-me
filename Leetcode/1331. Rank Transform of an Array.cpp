#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted_arr = arr;
        sort(sorted_arr.begin(), sorted_arr.end());
        
        unordered_map<int, int> rank_map;
        int rank = 1;
        
        for (int num : sorted_arr) {
            if (rank_map.find(num) == rank_map.end()) {
                rank_map[num] = rank;
                rank++;
            }
        }
        
        vector<int> ans;
        ans.reserve(arr.size());
        for (int num : arr) {
            ans.push_back(rank_map[num]);
        }
        
        return ans;
    }
};

int main() {
    Solution solver;
    vector<int> arr = {40, 10, 20, 30, 10};
    vector<int> result = solver.arrayRankTransform(arr);
    
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl; // Expected: 4 1 2 3 1
    return 0;
}