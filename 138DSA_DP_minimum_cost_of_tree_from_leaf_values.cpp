/*
LEETCODE    

1130. Minimum Cost Tree From Leaf Values
Attempted
Medium
Topics
Companies
Hint
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.

 

Example 1:


Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.
Example 2:


Input: arr = [4,11]
Output: 44
 

Constraints:

2 <= arr.length <= 40
1 <= arr[i] <= 15
It is guaranteed that the answer fits into a 32-bit signed integer (i.e., it is less than 231).


*/



#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

class Solution {
public:
    // Recursive approach (no memoization)
    int solveRecu(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right) {
        if (left == right) return 0;

        int ans = INT_MAX;
        for (int i = left; i < right; i++) {
            ans = min(ans,
                      maxi[{left, i}] * maxi[{i + 1, right}] +
                      solveRecu(arr, maxi, left, i) +
                      solveRecu(arr, maxi, i + 1, right));
        }

        return ans;
    }

    // Top-down DP with memoization
    int solveMemo(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right, vector<vector<int>> &dp) {
        if (left == right) return 0;
        if (dp[left][right] != -1) return dp[left][right];

        int ans = INT_MAX;
        for (int i = left; i < right; i++) {
            int cost = maxi[{left, i}] * maxi[{i + 1, right}] +
                       solveMemo(arr, maxi, left, i, dp) +
                       solveMemo(arr, maxi, i + 1, right, dp);
            ans = min(ans, cost);
        }

        return dp[left][right] = ans;
    }

    // Bottom-up DP with tabulation
    int solveTab(vector<int> &arr, map<pair<int, int>, int> &maxi) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int length = 2; length <= n; length++) {
            for (int left = 0; left <= n - length; left++) {
                int right = left + length - 1;
                dp[left][right] = INT_MAX;

                for (int k = left; k < right; k++) {
                    int cost = maxi[{left, k}] * maxi[{k + 1, right}] +
                               dp[left][k] + dp[k + 1][right];
                    dp[left][right] = min(dp[left][right], cost);
                }
            }
        }

        return dp[0][n - 1];
    }

    // Main function
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        map<pair<int, int>, int> maxi;

        // Precomputing maximum values for all subarrays
        for (int i = 0; i < n; i++) {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < n; j++) {
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }

        // Uncomment the approach you want to use:

        // return solveRecu(arr, maxi, 0, n - 1); // Recursive solution

        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solveMemo(arr, maxi, 0, n - 1, dp); // Memoized solution

        return solveTab(arr, maxi); // Tabulation solution (currently active)
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> arr = {6, 2, 4};

    int result = sol.mctFromLeafValues(arr);
    cout << "Minimum cost to build the tree: " << result << endl;

    return 0;
}
