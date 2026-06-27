#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int max_len = 1;

        if (freq.count(1)) {
            int count1 = freq[1];
            max_len = max(max_len, count1 % 2 == 0 ? count1 - 1 : count1);
        }

        for (auto it = freq.begin(); it != freq.end(); ++it) {
            long long key = it->first;
            if (key == 1) continue;

            long long current = key;
            int current_len = 0;

            while (freq.count(current) && freq[current] >= 2) {
                current_len += 2;
                current = current * current;
            }

            if (freq.count(current) && freq[current] >= 1) {
                current_len += 1;
            } else {
                current_len -= 1;
            }

            max_len = max(max_len, current_len);
        }

        return max_len;
    }
};

int main() {
    Solution solver;
    vector<int> nums = {5, 4, 1, 2, 2};
    cout << "Output: " << solver.maximumLength(nums) << " (Expected: 3)" << endl;
    return 0;
}