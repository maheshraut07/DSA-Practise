/**
 
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 


*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}


int longestCommonSubsequence(string text1, string text2) {
    // return solve(text1, text2, 0, 0);

      vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));  // step 1 = for solving it by using dp create an dp array it is 2D dp because it is changing 2 dimesions in recurrsive functino call 
        return solve1(text1, text2, 0, 0, dp);
}


// step1 = find the solution using recurrsion 
int solve(string &a, string &b, int i, int j) {
        if (i == a.length() || j == b.length()) 
            return 0;

        int ans = 0;
        if (a[i] == b[j]) 
            ans = 1 + solve(a, b, ++i, ++j);
        else 
            ans = max(solve(a, b, ++i, j), solve(a, b, i, ++j));

        return ans;
    }

// Approach 1 = top_down dp / memoization  , convert it into memoization / top down approach 
  int solve1(string &a, string &b, int i, int j, vector<vector<int>> &dp) {
        if (i == a.length() || j == b.length()) 
            return 0;

        if (dp[i][j] != -1) return dp[i][j]; // step 2  : add memoization to avoid repitive function call for the same set of arguments and to optimize it 

        int ans = 0;
        if (a[i] == b[j]) 
            ans = 1 + solve1(a, b, i + 1, j + 1, dp);
        else 
            ans = max(solve1(a, b, i + 1, j, dp), solve1(a, b, i, j + 1, dp));

        return dp[i][j] = ans;   // stpe 3 : save the answet in dp 
    }

// Approach2 = bottom up dp / tabulization method 

int solveTab(string a, string b){
    
}
