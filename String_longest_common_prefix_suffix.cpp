/*

30+ People have Claimed their 90% Refunds. Start Your Journey Today! 

banner
Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

NOTE: Prefix and suffix can be overlapping but they should not be equal to the entire string.

Example 1:

Input: s = "abab"
Output: 2
Explanation: "ab" is the longest proper 
prefix and suffix. 
Example 2:

Input: s = "aaaa"
Output: 3
Explanation: "aaa" is the longest proper 
prefix and suffix. 

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

int lps(string s) {
    int n = s.length();
    vector<int> lpsArray(n, 0);

    int len = 0; // Length of the previous longest prefix suffix

    // Start from index 1, as lps[0] is always 0
    int i = 1;

    while (i < n) {
        if (s[i] == s[len]) {   // if match found increase the length and update the lpsArray
            len++;
            lpsArray[i] = len;
            i++;
        } else {
            if (len != 0) {
                // Try to match with the previous prefix
                len = lpsArray[len - 1];
            } else {
                // No matching prefix found
                lpsArray[i] = 0;
                i++;
            }
        }
    }

    return lpsArray[n - 1];
}