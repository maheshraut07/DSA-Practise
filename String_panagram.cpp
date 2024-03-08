/*

Given a string s check if it is "Panagram" or not.

A "Panagram" is a sentence containing every letter in the English Alphabet.

Example 1:

Input:
s = "Bawds jog, flick quartz, vex nymph"
Output: 
1
Explanation: 
In the given input, there
are all the letters of the English
alphabet. Hence, the output is 1.
Example 2:

Input:
s = "sdfs"
Output: 
0
Explanation: 
In the given input, there
aren't all the letters present in the
English alphabet. Hence, the output
is 0.

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

bool checkPangram(const std::string& s) {
    std::map<char, int> m;

    // Initialize the map with characters 'a' to 'z'
    for (char c = 'a'; c <= 'z'; ++c) {
        m[c] = 0;
    }

    // Convert the string to lowercase and update the map
    for (char c : s) {
        if (isalpha(c)) {
            m[tolower(c)]++;
        }
    }

    // Check if any character count is zero
    for (const auto& i : m) {
        if (i.second == 0) {
            return false;
        }
    }

    return true;
}