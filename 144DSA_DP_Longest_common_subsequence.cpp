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

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Recursive approach
    int solveRecu(string a, string b, int i, int j) {
        if (i >= a.length() || j >= b.length()) return 0;

        if (a[i] == b[j]) 
            return 1 + solveRecu(a, b, i + 1, j + 1);
        else 
            return max(solveRecu(a, b, i + 1, j), solveRecu(a, b, i, j + 1));
    }

    // Memoization approach
    int solveMemo(string a, string b, int i, int j, vector<vector<int>> &dp) {
        if (i >= a.length() || j >= b.length()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (a[i] == b[j]) 
            dp[i][j] = 1 + solveMemo(a, b, i + 1, j + 1, dp);
        else 
            dp[i][j] = max(solveMemo(a, b, i + 1, j, dp), solveMemo(a, b, i, j + 1, dp));

        return dp[i][j];
    }

    // Tabulation approach
    int solveTab(string a, string b) {
        int n = a.length();
        int m = b.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (a[i] == b[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        return dp[0][0];
    }

    // Space-optimized approach
    int solveSpace(string a, string b){
        int n = a.length();
        int m = b.length();
        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (a[i] == b[j])
                    curr[j] = 1 + next[j + 1];
                else
                    curr[j] = max(next[j], curr[j + 1]);
            }
            next = curr;
        }

        return next[0];
    }

    // Entry function
    int longestCommonSubsequence(string text1, string text2) {
        // Uncomment the approach you want to use:
        // return solveRecu(text1, text2, 0, 0);
        // vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        // return solveMemo(text1, text2, 0, 0, dp);
        // return solveTab(text1, text2);
        return solveSpace(text1, text2);  // default approach
    }
};

// Main function
int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    Solution sol;
    int lcsLength = sol.longestCommonSubsequence(str1, str2);

    cout << "The length of the Longest Common Subsequence is: " << lcsLength << endl;

    return 0;
}
