/*
GFG - Get Minimum Squares

Given a number n, find the minimum number of perfect squares (square of an integer) that sum up to n. 

Examples:

Input: n = 100
Output: 1
Explanation: 10 * 10 = 100
Input: n = 6
Output: 3
Explanation = 1 * 1 + 1 * 1 + 2 * 2 = 6 
Expected Time Complexity: O(n * sqrt(n))
Expected Space Complexity: O(n)

Constraints:
1 <= n <= 104

Company Tags
AmazonMicrosoftWipro
Topic Tags
Related Articles
If you are facing any issue on this page. Please let us k
 */


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// ------------------------ 1. Recursive ------------------------
int solveRecursive(int n) {
    if (n == 0) return 0;

    int ans = n;
    for (int i = 1; i * i <= n; i++) {
        ans = min(ans, 1 + solveRecursive(n - i * i));
    }
    return ans;
}

// ------------------------ 2. Memoization ------------------------
int solveMemo(int n, vector<int>& dp) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];

    int ans = n;
    for (int i = 1; i * i <= n; i++) {
        ans = min(ans, 1 + solveMemo(n - i * i, dp));
    }
    return dp[n] = ans;
}

// ------------------------ 3. Tabulation ------------------------
int solveTab(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], 1 + dp[i - j * j]);
        }
    }
    return dp[n];
}


// ------------------------ Main Function ------------------------
int main() {
    int n = 100;

    // 1. Recursive
    cout << "Recursive: " << solveRecursive(n) << endl;

    // 2. Memoization
    vector<int> dp(n + 1, -1);
    cout << "Memoization: " << solveMemo(n, dp) << endl;

    // 3. Tabulation
    cout << "Tabulation: " << solveTab(n) << endl;


    return 0;
}
