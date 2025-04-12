/*
LEETCDOE

1039. Minimum Score Triangulation of Polygon

Medium
Topics
Companies
Hint
You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex in clockwise order.

Polygon triangulation is a process where you divide a polygon into a set of triangles and the vertices of each triangle must also be vertices of the original polygon. Note that no other shapes other than triangles are allowed in the division. This process will result in n - 2 triangles.

You will triangulate the polygon. For each triangle, the weight of that triangle is the product of the values at its vertices. The total score of the triangulation is the sum of these weights over all n - 2 triangles.

Return the minimum possible score that you can achieve with some triangulation of the polygon.

 

Example 1:



Input: values = [1,2,3]

Output: 6

Explanation: The polygon is already triangulated, and the score of the only triangle is 6.

Example 2:



Input: values = [3,7,4,5]

Output: 144

Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.
The minimum score is 144.

Example 3:



Input: values = [1,3,1,4,1,5]

Output: 13

Explanation: The minimum score triangulation is 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.

 

Constraints:

n == values.length
3 <= n <= 50
1 <= values[i] <= 100

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:

    // 1. Recursive Approach (Not used in final call)
    int solveRecu(vector<int> &v, int i, int j) {
        if(i + 1 == j) return 0;

        int ans = INT_MAX;

        for(int k = i + 1; k < j; k++) {
            ans = min(ans, v[i]*v[j]*v[k] + solveRecu(v, i, k) + solveRecu(v, k, j));
        }

        return ans;
    }

    // 2. Memoization Approach (Not used in final call)
    int solveMemo(vector<int> &v, int i, int j, vector<vector<int>> &dp) {
        if(i + 1 == j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;

        for(int k = i + 1; k < j; k++) {
            ans = min(ans, v[i]*v[j]*v[k] + solveMemo(v, i, k, dp) + solveMemo(v, k, j, dp));
        }

        dp[i][j] = ans;
        return dp[i][j];
    }

    // 3. Tabulation (Bottom-Up DP)
    int solveTab(vector<int> &v) {
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        // Fill the table in bottom-up manner
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 2; j < n; j++) {
                int ans = INT_MAX;
                for(int k = i + 1; k < j; k++) {
                    ans = min(ans, v[i] * v[j] * v[k] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][n - 1];
    }

    // Main driver for the solution
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();

        // You can test any of the three methods here:
        // return solveRecu(values, 0, n-1);
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solveMemo(values, 0, n-1, dp);
        return solveTab(values);  // Using bottom-up DP
    }
};

// Main function
int main() {
    Solution sol;

    vector<int> values1 = {1, 2, 3};
    vector<int> values2 = {3, 7, 4, 5};
    vector<int> values3 = {1, 3, 1, 4, 1, 5};

    cout << "Minimum score for [1, 2, 3]: " << sol.minScoreTriangulation(values1) << endl; // Output: 6
    cout << "Minimum score for [3, 7, 4, 5]: " << sol.minScoreTriangulation(values2) << endl; // Output: 144
    cout << "Minimum score for [1, 3, 1, 4, 1, 5]: " << sol.minScoreTriangulation(values3) << endl; // Output: 13

    return 0;
}
