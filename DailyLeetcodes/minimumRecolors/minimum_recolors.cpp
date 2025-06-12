// https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/?envType=daily-question&envId=2025-03-08

#include <string>
#include <iostream>

using std::string;

int minimumRecolors(string blocks, int k) {
    int blocks_len = blocks.length();
    int min_recolors = blocks_len;
    int consec_blacks;
    int cur_recolors;

    int i = 0;
    while (i < blocks_len) {
        consec_blacks = 0;
        cur_recolors = 0;

        for (int j = i; j < blocks_len && consec_blacks < k; j++) {
            if (blocks[j] == 'W') {
                cur_recolors++;
            } 
            consec_blacks++;
        }

        if (consec_blacks >= k && cur_recolors < min_recolors) {
            min_recolors = cur_recolors;
        }

        while (i < blocks_len && blocks[i] != 'W') {
            i++;
        }  
        if (blocks[i] == 'W') {
            i++;
        }
    }
    return min_recolors;
}

int minimumRecolorsWindow(string blocks, int k) {
    int ret = blocks.length();
    int blacks_in_window = 0;

    for (int i = 0; i < blocks.length(); i++) {
        if (i - k >= 0 && blocks[i - k] == 'B') blacks_in_window--; 
        if (blocks[i] == 'B') blacks_in_window++;
        // k - blacks = whites
        if (ret > k - blacks_in_window) ret = k - blacks_in_window;
    }

    return ret;
}

int main() {
    string blocks = "BWBBBWWWBB";
    if (minimumRecolorsWindow(blocks, 5) != 1) {
        std::cout << "fail";
    } else {
        std::cout << "success";
    }
}