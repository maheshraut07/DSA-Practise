/*

Given a string S consisting of lowercase Latin Letters. Return the first non-repeating character in S. If there is no non-repeating character, return '$'.

Example 1:

Input:
S = hello
Output: h
Explanation: In the given string, the
first character which is non-repeating
is h, as it appears first and there is
no other 'h' in the string.
Example 2:

Input:
S = zxvczbtxyzvy
Output: c
Explanation: In the given string, 'c' is
the character which is non-repeating. 

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

   
char nonrepeatingCharacter(string S) {
    queue<char> q;
    unordered_map<char, int> map;

    for (int i = 0; i < S.length(); i++) {
        char ch = S[i];

        map[ch]++;  // Increase count

        q.push(ch);  // Push in the queue

        while (!q.empty() && map[q.front()] > 1) {
            q.pop();  // Remove repeating characters from front of the queue 
        }
    }

    while (!q.empty()) {
        if (map[q.front()] == 1) {
            return q.front();  // First non-repeating character found
        }
        q.pop();
    }

    return '$';  // No non-repeating character found
}