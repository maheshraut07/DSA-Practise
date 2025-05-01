/*

LEETCODE 


Code
Testcase
Testcase
Test Result
516. Longest Palindromic Subsequence
Solved
Medium
Topics
Companies
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Recursive approach (not used in final call)
    int solveRecu(string a, string b, int i, int j) {
        if (i >= a.length() || j >= b.length()) return 0;

        if (a[i] == b[j]) 
            return 1 + solveRecu(a, b, i + 1, j + 1);
        else 
            return max(solveRecu(a, b, i + 1, j), solveRecu(a, b, i, j + 1));
    }

    // Memoization approach (not used in final call)
    int solveMemo(string a, string b, int i, int j, vector<vector<int>> &dp) {
        if (i >= a.length() || j >= b.length()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (a[i] == b[j]) 
            dp[i][j] = 1 + solveMemo(a, b, i + 1, j + 1, dp);
        else 
            dp[i][j] = max(solveMemo(a, b, i + 1, j, dp), solveMemo(a, b, i, j + 1, dp));

        return dp[i][j];
    }

    // Tabulation approach (not used in final call)
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

    // Space optimized approach (used in final call)
    int solveSpace(string a, string b) {
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

    // Function to compute longest palindromic subsequence
    int longestPalindromeSubseq(string s) {
        string revStr = s;
        reverse(revStr.begin(), revStr.end());
        return solveSpace(s, revStr);
    }
};

int main() {
    Solution sol;
    string input;

    cout << "Enter a string: ";
    cin >> input;

    int result = sol.longestPalindromeSubseq(input);

    cout << "The length of the longest palindromic subsequence is: " << result << endl;

    return 0;
}
