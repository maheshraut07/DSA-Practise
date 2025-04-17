/*
GFG 

Partition Equal Subset Sum
Difficulty: MediumAccuracy: 30.24%Submissions: 265K+Points: 4
Given an array arr[], determine if it can be partitioned into two subsets such that the sum of elements in both parts is the same.

Note: Each element must be in exactly one subset.

Examples:

Input: arr = [1, 5, 11, 5]
Output: true
Explanation: The two parts are [1, 5, 5] and [11].
Input: arr = [1, 3, 5]
Output: false
Explanation: This array can never be partitioned into two such parts.
Constraints:
1 ≤ arr.size ≤ 100
1 ≤ arr[i] ≤ 200


*/

#include <iostream>
#include <vector>
using namespace std;

bool solveRecu(int index, vector<int> &arr, int n, int target) {
    if (index > n) return false;
    if (target < 0) return false;
    if (target == 0) return true;

    bool include = solveRecu(index + 1, arr, n, target - arr[index]);
    bool exclude = solveRecu(index + 1, arr, n, target);

    return include || exclude;
}

bool solveMemo(int index, vector<int> &arr, int n, int target, vector<vector<int>> &dp) {
    if (index > n) return false;
    if (target < 0) return false;
    if (target == 0) return true;

    if (dp[index][target] != -1) return dp[index][target];

    bool include = solveMemo(index + 1, arr, n, target - arr[index], dp);
    bool exclude = solveMemo(index + 1, arr, n, target, dp);

    return dp[index][target] = include || exclude;
}

bool solveTab(int index, vector<int> &arr, int n, int t) {
    vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int index = n - 1; index >= 0; index--) {
        for (int target = 0; target <= t; target++) {
            bool include = 0;
            if (target - arr[index] >= 0)
                include = dp[index + 1][target - arr[index]];

            bool exclude = dp[index + 1][target];

            dp[index][target] = include || exclude;
        }
    }

    return dp[0][t];
}

bool solveSpace(int index, vector<int> &arr, int n, int t) {
    vector<int> curr(t + 1, 0);
    vector<int> next(t + 1, 0);

    curr[0] = 1;
    next[0] = 1;

    for (int index = n - 1; index >= 0; index--) {
        for (int target = 0; target <= t; target++) {
            bool include = 0;
            if (target - arr[index] >= 0)
                include = next[target - arr[index]];

            bool exclude = next[target];

            curr[target] = include || exclude;
        }

        next = curr;
    }

    return next[t];
}

bool equalPartition(vector<int> &arr) {
    int total = 0;
    for (int element : arr) total += element;

    if (total % 2 != 0) return 0;

    int target = total / 2;
    int n = arr.size();

    // return solveRecu(0, arr, n, target);
    // vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    // return solveMemo(0, arr, n, target, dp);
    // return solveTab(0, arr, n, target);
    return solveSpace(0, arr, n, target);
}

int main() {
    vector<int> arr1 = {1, 5, 11, 5};
    vector<int> arr2 = {1, 3, 5};

    cout << "Test Case 1: " << (equalPartition(arr1) ? "true" : "false") << endl;
    cout << "Test Case 2: " << (equalPartition(arr2) ? "true" : "false") << endl;

    return 0;
}
