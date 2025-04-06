// https://neetcode.io/problems/longest-consecutive-sequence

#include <vector>
#include <iostream>
#include <unordered_set>

using std::vector;
using std::cout;
using std::endl;

int longestConsecutive(vector<int>& nums) {
    std::unordered_set<int> num_set(nums.begin(), nums.end());
    int max_streak = 0;
    int cur_streak;
    int cur_num;
    
    for (int num: nums) {
        cur_streak = 1;
        if (num_set.find(num - 1) == num_set.end()) {
            while (num_set.find(++num) != num_set.end()) { cur_streak++; }
        }

        if (cur_streak > max_streak) {
            max_streak = cur_streak;
        }
    }

    return max_streak;
}

int main() {
    vector<int> vec = { 0, 2, 5, 1, 8, 3, 4, 10, 6 };
    cout << "longest streak: " << longestConsecutive(vec) << endl;
}