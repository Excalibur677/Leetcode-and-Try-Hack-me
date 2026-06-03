#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    int calculateMinTime(const vector<int>& start1, const vector<int>& duration1, 
                         const vector<int>& start2, const vector<int>& duration2) {
        
        int minFirstFinish = INT_MAX;
        for (size_t i = 0; i < start1.size(); i++) {
            minFirstFinish = min(minFirstFinish, start1[i] + duration1[i]);
        }
        
        int totalMinFinish = INT_MAX;
        for (size_t j = 0; j < start2.size(); j++) {
            int secondStart = max(minFirstFinish, start2[j]);
            int secondFinish = secondStart + duration2[j];
            totalMinFinish = min(totalMinFinish, secondFinish);
        }
        
        return totalMinFinish;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int landFirst = calculateMinTime(landStartTime, landDuration, waterStartTime, waterDuration);
        int waterFirst = calculateMinTime(waterStartTime, waterDuration, landStartTime, landDuration);
        
        return min(landFirst, waterFirst);
    }
};

int main() {
    Solution solver;
    
    vector<int> landStartTime = {2, 8};
    vector<int> landDuration = {4, 1};
    vector<int> waterStartTime = {6};
    vector<int> waterDuration = {3};
    
    int result = solver.earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);
    cout << "Earliest Finish Time: " << result << endl;
    
    return 0;
}