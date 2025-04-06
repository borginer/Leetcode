// https://neetcode.io/problems/max-water-container

#include <vector>
#include <iostream> 

using std::vector;
using std::cout;
using std::endl;

int maxArea(vector<int>& heights) {
    int max_area = 0;
    int left = 0;
    int right = heights.size() - 1;

    int area;

    while (left != right) {
        area = (right - left) * std::min(heights[left], heights[right]);
        if (area > max_area) {
            max_area = area;
        }    
        if (heights[right] > heights[left]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;
}

int main() {
    vector<int> h = { 1, 5, 2, 6, 8, 6 };
    cout << maxArea(h) << endl;
    cout << (maxArea(h) == 20) << endl;
}