/*

GFG Question - Largest square formed in a matrix

Difficulty: MediumAccuracy: 36.98%Submissions: 115K+Points: 4Average Time: 20m
Given a binary matrix mat, find out the maximum length of a side of a square sub-matrix with all 1s.

Examples:

Input: mat = [[0, 1, 1, 0, 1], 
              [1, 1, 0, 1, 0],
              [0, 1, 1, 1, 0],
              [1, 1, 1, 1, 0],
              [1, 1, 1, 1, 1],
              [0, 0, 0, 0, 0]]
Output: 3
Explanation: 

The maximum length of a side of the square sub-matrix is 3 where every element is 1.
Input: mat = [[1, 1], 
              [1, 1]]
Output: 2
Explanation: The maximum length of a side of the square sub-matrix is 2. The matrix itself is the maximum sized sub-matrix in this case.
Input: mat = [[0, 0], 
              [0, 0]]
Output: 0
Explanation: There is no 1 in the matrix.
Constraints:
1 ≤ mat.size(), mat[i].size() ≤ 500
0 ≤ mat[i][j] ≤ 1 

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1. Recursive (Brute Force)
int solveRecu(vector<vector<int>>& mat, int i, int j, int& maxi) {
    if (i >= mat.size() || j >= mat[0].size()) return 0;

    int right = solveRecu(mat, i, j + 1, maxi);
    int diagonal = solveRecu(mat, i + 1, j + 1, maxi);
    int down = solveRecu(mat, i + 1, j, maxi);

    int ans = 0;
    if (mat[i][j] == 1) {
        ans = 1 + min({right, diagonal, down});
        maxi = max(maxi, ans);
    }

    return ans;
}

// 2. Memoization (Top-Down DP)
int solveMemo(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& dp, int& maxi) {
    if (i >= mat.size() || j >= mat[0].size()) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int right = solveMemo(mat, i, j + 1, dp, maxi);
    int diagonal = solveMemo(mat, i + 1, j + 1, dp, maxi);
    int down = solveMemo(mat, i + 1, j, dp, maxi);

    int ans = 0;
    if (mat[i][j] == 1) {
        ans = 1 + min({right, diagonal, down});
        maxi = max(maxi, ans);
    }

    return dp[i][j] = ans;
}

// 3. Tabulation (Bottom-Up DP)
int solveTabu(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // extra row & column to avoid bounds
    int maxi = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (mat[i][j] == 1) {
                int right = dp[i][j + 1];
                int diagonal = dp[i + 1][j + 1];
                int down = dp[i + 1][j];
                dp[i][j] = 1 + min({right, diagonal, down});
                maxi = max(maxi, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return maxi;
}

// 4. Space Optimized DP
int solveSpaceOpt(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<int> curr(m + 1, 0);
    vector<int> next(m + 1, 0);
    int maxi = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int ans = 0;
            if (mat[i][j] == 1) {
                int right = curr[j + 1];
                int diagonal = next[j + 1];
                int down = next[j];
                ans = 1 + min({right, diagonal, down});
                maxi = max(maxi, ans);
            }
            curr[j] = ans;
        }
        next = curr;
    }

    return maxi;
}

// Main function to test all approaches
int main() {
    vector<vector<int>> mat = {
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}
    };

    int maxiRecu = 0;
    solveRecu(mat, 0, 0, maxiRecu);
    cout << "Recursion: " << maxiRecu << endl;

    int maxiMemo = 0;
    vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), -1));
    solveMemo(mat, 0, 0, dp, maxiMemo);
    cout << "Memoization: " << maxiMemo << endl;

    int maxiTabu = solveTabu(mat);
    cout << "Tabulation: " << maxiTabu << endl;

    int maxiOpt = solveSpaceOpt(mat);
    cout << "Space Optimized: " << maxiOpt << endl;

    return 0;
}
