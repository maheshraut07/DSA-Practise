/*


Code
Testcase
Testcase
Test Result
96. Unique Binary Search Trees
Solved
Medium
Topics
Companies
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 

Example 1:


Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 19

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 1. Recursive approach (very slow for large n)
    int solveRecu(int n) {
        if(n <= 1) return 1;

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += solveRecu(i - 1) * solveRecu(n - i);
        }

        return ans;
    }

    // 2. Memoization (Top-Down DP)
    int solveMemo(int n, vector<int> &dp) {
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += solveMemo(i - 1, dp) * solveMemo(n - i, dp);
        }

        return dp[n] = ans;
    }

    // 3. Tabulation (Bottom-Up DP)
    int solveTab(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        // i -> number of nodes
        for(int i = 2; i <= n; i++) {
            // j -> root node
            for(int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }

    // 4. Catalan Number using Formula: Cn = (2n)! / ((n+1)! * n!)
    long long factorial(int n) {
        if(n <= 1) return 1;
        return n * factorial(n - 1);
    }

    int catalanUsingFormula(int n) {
        long long numerator = factorial(2 * n);
        long long denominator = factorial(n + 1) * factorial(n);
        return numerator / denominator;
    }

    // Entry method to use any approach
    int numTrees(int n) {
        // return solveRecu(n);  // Brute force recursive
        // vector<int> dp(n + 1, -1);
        // return solveMemo(n, dp);  // Memoization
        // return solveTab(n);       // Tabulation

        return catalanUsingFormula(n); // Using factorial-based Catalan number
    }
};

// Main function to run and test the code
int main() {
    Solution obj;
    int n;

    cout << "Enter the number of nodes (n): ";
    cin >> n;

    int result = obj.numTrees(n);
    cout << "Number of unique BSTs with " << n << " nodes: " << result << endl;

    return 0;
}
