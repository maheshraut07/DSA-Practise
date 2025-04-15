/*
LEETCODE
same as like maximum sum of non-adjacent elements and hosue robbery problem

1388. Pizza With 3n Slices
Hard
Topics
Companies
Hint
There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:

You will pick any pizza slice.
Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
Your friend Bob will pick the next slice in the clockwise direction of your pick.
Repeat until there are no more slices of pizzas.
Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.

 

Example 1:


Input: slices = [1,2,3,4,5,6]
Output: 10
Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively. Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.
Example 2:


Input: slices = [8,9,8,6,1,1]
Output: 16
Explanation: Pick pizza slice of size 8 in each turn. If you pick slice with size 9 your partners will pick slices of size 8.
 

Constraints:

3 * n == slices.length
1 <= slices.length <= 500
1 <= slices[i] <= 1000


*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Pure Recursion
    int solveRecu(int index, int endIndex, vector<int> &slices, int n){
        if(n == 0 || index > endIndex) return 0;

        int include = slices[index] + solveRecu(index + 2, endIndex, slices, n - 1);
        int execlude = solveRecu(index + 1, endIndex, slices, n);

        return max(include, execlude);
    }

    // Recursion + Memoization
    int solveMemo(int index, int endIndex, vector<int> &slices, int n, vector<vector<int>> &dp){
        if(n == 0 || index > endIndex) return 0;

        if(dp[index][n] != -1) return dp[index][n];

        int include = slices[index] + solveMemo(index + 2, endIndex, slices, n - 1, dp);
        int execlude = solveMemo(index + 1, endIndex, slices, n, dp);

        return dp[index][n] = max(include, execlude);
    }

    // Tabulation (Bottom-Up DP)
    int solveTab(vector<int>& slices){
        int k = slices.size();

        vector<vector<int>> dp1(k+2, vector<int>((k/3) + 1, 0));
        vector<vector<int>> dp2(k+2, vector<int>((k/3) + 1, 0));

        for(int index = k - 2; index >= 0; index--){
            for(int n = 1; n <= k / 3; n++){
                int include = slices[index] + dp1[index + 2][n - 1];
                int execlude = dp1[index + 1][n];
                dp1[index][n] = max(include, execlude);
            }
        }

        int case1 = dp1[0][k / 3];

        for(int index = k - 1; index >= 1; index--){
            for(int n = 1; n <= k / 3; n++){
                int include = slices[index] + dp2[index + 2][n - 1];
                int execlude = dp2[index + 1][n];
                dp2[index][n] = max(include, execlude);
            }
        }

        int case2 = dp2[1][k / 3];
        return max(case1, case2);
    }

    // Space Optimization
    int solveSpace(vector<int>& slices){
        int k = slices.size();

        vector<int> prev1(k + 2, 0), curr1(k + 2, 0), next1(k + 2, 0);

        for(int index = k - 2; index >= 0; index--){
            for(int n = 1; n <= k / 3; n++){
                int include = slices[index] + next1[n - 1];
                int execlude = curr1[n];
                prev1[n] = max(include, execlude);
            }
            next1 = curr1;
            curr1 = prev1;
        }

        int case1 = curr1[k / 3];

        vector<int> prev2(k + 2, 0), curr2(k + 2, 0), next2(k + 2, 0);

        for(int index = k - 1; index >= 1; index--){
            for(int n = 1; n <= k / 3; n++){
                int include = slices[index] + next2[n - 1];
                int execlude = curr2[n];
                prev2[n] = max(include, execlude);
            }
            next2 = curr2;
            curr2 = prev2;
        }

        int case2 = curr2[k / 3];
        return max(case1, case2);
    }

    int maxSizeSlices(vector<int>& slices){
        int k = slices.size();
        int n = k / 3;

        // Uncomment for recursive / memo / tabulation
        // int case1 = solveRecu(0, k - 2, slices, n);
        // int case2 = solveRecu(1, k - 1, slices, n);
        // vector<vector<int>> dp1(k, vector<int>(n + 1, -1));
        // vector<vector<int>> dp2(k, vector<int>(n + 1, -1));
        // int case1 = solveMemo(0, k - 2, slices, n, dp1);
        // int case2 = solveMemo(1, k - 1, slices, n, dp2);
        // return max(case1, case2);

        // Best optimized version
        return solveSpace(slices);
    }
};

int main() {
    Solution sol;

    vector<int> slices1 = {1, 2, 3, 4, 5, 6};
    vector<int> slices2 = {8, 9, 8, 6, 1, 1};

    cout << "Max slice sum for test case 1: " << sol.maxSizeSlices(slices1) << endl; // Expected: 10
    cout << "Max slice sum for test case 2: " << sol.maxSizeSlices(slices2) << endl; // Expected: 16

    return 0;
}


/*

Function Explanation:
🔹 solveRecu(...)
Pure recursion.

Tries every possible way to pick n slices (where you skip next and previous slices due to Alice and Bob).

Very slow for large inputs.

🔹 solveMemo(...)
Same as solveRecu but adds memoization (dp array).

Stores already computed results to avoid re-computation.

🔹 solveTab(...)
Bottom-up Dynamic Programming.

Builds solution iteratively rather than recursively.

Handles two cases:

Exclude last slice (index 0 to k-2)

Exclude first slice (index 1 to k-1)

🔹 solveSpace(...)
Most optimized version using space optimization over tabulation.

Reduces 2D dp to just three 1D arrays (prev, curr, next).

Works efficiently with minimal space.

🔹 maxSizeSlices(...)
Main driver.

Calculates the answer using the best version of the function (currently solveSpace).

You can easily switch to other methods by commenting/uncommenting.




*/