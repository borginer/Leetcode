//https://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/?envType=daily-question&envId=2025-04-30

#include <vector>

using std::vector;

// given: 1 <= num <= 10^5
bool even_digit_num(int num) {
    for (int i = 10; i <= 100000; i*=100) {
        if (num / i > 0 && num / i < 10) {
            return true;
        }
    }
    return false;
}

int findNumbers(vector<int>& nums) {
    int even_digit_nums = 0;
    
    for (int& num: nums) {
        if (even_digit_num(num)) {
            even_digit_nums++;
        }
    }
    return even_digit_nums;
}