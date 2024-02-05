/*

76. Minimum Window Substring
Solved
Hard
Topics
Companies
Hint
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}


class Solution {
public:
    string minWindow(string s, string t) {
        int best = 1e9, start = 0;
        int l = 0, r= 0;

        unordered_map<char,int> fs,ft;

        for(auto i : t) ++ft[i];

        while(r < s.size()){
            ++fs[s[r++]];

            while(1){
                bool ok = 1;

                for(auto x : ft){
                    if(fs[x.first] < x.second){
                        ok = 0;
                        break;
                    }
                }

                if(!ok) break;
                if(r - l < best){
                    best = r -l;
                    start = l;
                }

                --fs[s[l++]];
            }
        }

        if(best == 1e9) return "";
        else return s.substr(start,best);
    }
};