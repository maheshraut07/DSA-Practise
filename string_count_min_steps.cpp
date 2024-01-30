/*
You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.

 

Example 1:

Input: s = "bab", t = "aba"
Output: 1
Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.
Example 2:

Input: s = "leetcode", t = "practice"
Output: 5
Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.
Example 3:

Input: s = "anagram", t = "mangaar"
Output: 0
Explanation: "anagram" and "mangaar" are anagrams. 
 
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

class Solution {
public:
   int minSteps(string s, string t) {
    unordered_map<char, int> m1;
    unordered_map<char, int> m2;

    for (char i : s) m1[i]++;
    for (char i : t) m2[i]++;

    int steps = 0;

    for (auto i : m1) {
        char c = i.first;
        if (m2.find(c) == m2.end()) {
            // Character not present in t, all occurrences need to be replaced
            steps += i.second;
        } 
        else {
            // Character present in t, calculate the difference in occurrences
            steps = steps +  max(0, i.second - m2[c]);
        }
    }

    return steps;  
    }
};

/*
another approach


class Solution {
public:
    int minSteps(std::string s, std::string t) {
        std::vector<int> count_s(26, 0);
        std::vector<int> count_t(26, 0);

        for (char ch : s) {
            count_s[ch - 'a']++;
        }

        for (char ch : t) {
            count_t[ch - 'a']++;
        }

        int steps = 0;
        for (int i = 0; i < 26; i++) {
            steps += std::abs(count_s[i] - count_t[i]);
        }

        return steps / 2;  
    }
};*/