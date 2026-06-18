#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;
        double minuteAngle = minutes * 6.0;
       
        double diff = abs(hourAngle - minuteAngle);
        
      
        return min(diff, 360.0 - diff);
    }
};

int main() {
    Solution solver;
    
   
    cout << "Angle at 12:30 -> " << solver.angleClock(12, 30) << "°" << endl; 
   
    cout << "Angle at 3:30 -> " << solver.angleClock(3, 30) << "°" << endl;   
    
    return 0;
}