/**
 
Given an array of strings arr[] of size n, a string str and an integer k. The task is to find the count of strings in arr[] whose prefix of length k matches with the k-length prefix of str.

Example 1:

Input:
n = 6
arr[] = {“abba”, “abbb”, “abbc”, “abbd”, 
“abaa”, “abca”}
str = “abbg”
k = 3
Output: 
4 
Explanation:
“abba”, “abbb”, “abbc” and “abbd” have their prefix of length 3 equal to 3-length prefix of str i.e., "abb".
Example 2:

Input:
n = 3
arr[] = {“geeks”, “geeksforgeeks”, “forgeeks”}
str = “ge”
k = 5
Output: 
0
Explanation:
There do not exists any prefix of str with length 5. So, there are no matches possible.


*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

int klengthpref(string arr[], int n, int k, string str) {
    if (k > str.length()) return 0;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        bool match = true;

        for (int j = 0; j < k; j++) {    // it will run only k times because we have to check only k characters from the provided str with the every word of the string array 
            if (arr[i].size() <= j || str[j] != arr[i][j]) {  // check the every character of 1st word of the string array with every character of the str for all the word of the string array 
                match = false;    // if characters does not match make it false and break the loop 
                break;
            }
        }

        if (match) cnt++; // if it matches with the word of the string array increment the count 
    }

    return cnt;
}