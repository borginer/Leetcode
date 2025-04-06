// https://neetcode.io/problems/string-encode-and-decode

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

string encode(vector<string>& strs) {
    string enc;
    int len;
    
    for (string& s : strs) {
        len = s.size();
        enc += std::to_string(len);
        enc += '#';
        enc += s;
    }

    return enc;
}

vector<string> decode(string s) {
    vector<string> dec;
    
    int num_start;
    int len_val;

    int i = 0;
    while(i < s.size()) {
        num_start = i;
        
        while (s[i] >= '0' && s[i] <= '9') { i++; }
        len_val = std::stoi(s.substr(num_start, i - num_start));
  
        i++; // skip the #

        dec.push_back(s.substr(i, len_val));
        i+= len_val;
    }

    return dec;
}

int main() {
    vector<string> s = {"but", "hands", "of" ,"gold", "are", "always", "cold", "but a woman's hands are warm" };
    cout << encode(s);
    vector<string> s2 = decode(encode(s));
    cout << (s == s2) << endl;
}