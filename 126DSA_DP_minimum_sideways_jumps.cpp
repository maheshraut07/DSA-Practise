/*

LEETCODE

1824. Minimum Sideway Jumps

Medium
Topics
Companies
Hint
There is a 3 lane road of length n that consists of n + 1 points labeled from 0 to n. A frog starts at point 0 in the second lane and wants to jump to point n. However, there could be obstacles along the way.

You are given an array obstacles of length n + 1 where each obstacles[i] (ranging from 0 to 3) describes an obstacle on the lane obstacles[i] at point i. If obstacles[i] == 0, there are no obstacles at point i. There will be at most one obstacle in the 3 lanes at each point.

For example, if obstacles[2] == 1, then there is an obstacle on lane 1 at point 2.
The frog can only travel from point i to point i + 1 on the same lane if there is not an obstacle on the lane at point i + 1. To avoid obstacles, the frog can also perform a side jump to jump to another lane (even if they are not adjacent) at the same point if there is no obstacle on the new lane.

For example, the frog can jump from lane 3 at point 3 to lane 1 at point 3.
Return the minimum number of side jumps the frog needs to reach any lane at point n starting from lane 2 at point 0.

Note: There will be no obstacles on points 0 and n.

 

Example 1:


Input: obstacles = [0,1,2,3,0]
Output: 2 
Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps (red arrows).
Note that the frog can jump over obstacles only when making side jumps (as shown at point 2).
Example 2:


Input: obstacles = [0,1,1,3,3,0]
Output: 0
Explanation: There are no obstacles on lane 2. No side jumps are required.
Example 3:


Input: obstacles = [0,2,1,0,3,0]
Output: 2
Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps.
 

Constraints:

obstacles.length == n + 1
1 <= n <= 5 * 105
0 <= obstacles[i] <= 3
obstacles[0] == obstacles[n] == 0

*/


#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:

    // solveRecu is used to solve using recursion.
   int solveRecu(vector<int> &obstacles, int currLane, int currPos ){

        // target 
        int n = obstacles.size() - 1 ; // given

        // if we reach the target
        if(currPos == n) return 0;
        
        // if there is no obstacles in the midway then go straight
        if(obstacles[currPos + 1] != currLane){
            return solveRecu(obstacles, currLane, currPos + 1);
        }

        else{
            // if there is an obstacle midway then we have to jump sideways
            // there are 3 lanes we can choose between them depending upon the obstacles
            int ans = INT_MAX;
            for(int i = 1 ; i <= 3; i++){

                // if the lane on which frog try to jump is not the same length itself 
                // and the there is no obstacle on the lane frog is trying to jump at that pos 
                // then frog can jump to that lane 
            
                if(currLane != i && obstacles[currPos] != i){
                    // we have to return the min sideways jumps 
                    ans = min (ans, 1 + solveRecu(obstacles, i, currPos));
                }
            }
            return ans; 
        }
   }
    // solveMemo is used to solve using recursion + memoization.
    int solveMemo(vector<int> &obstacles, int currLane, int currPos, vector<vector<int>> &dp) {
        int n = obstacles.size() - 1;

        // Base case
        if (currPos == n) return 0;

        // if answer is already stored in dp
        if (dp[currLane][currPos] != -1) return dp[currLane][currPos];

        // if there is no obstacle on current lane at next point
        if (obstacles[currPos + 1] != currLane) {
            return dp[currLane][currPos] = solveMemo(obstacles, currLane, currPos + 1, dp);
        } else {
            int ans = INT_MAX;

            // check for side jump
            for (int i = 1; i <= 3; i++) {
                if (currLane != i && obstacles[currPos] != i) {
                    ans = min(ans, 1 + solveMemo(obstacles, i, currPos, dp));
                }
            }

            return dp[currLane][currPos] = ans;
        }
    }

    // solveTab is used to solve using bottom up approach (tabulation).
    int solveTab(vector<int> &obstacles) {
        int n = obstacles.size() - 1;
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), 1e9)); // 4 rows for lanes 1-3, and index 0 unused

        // base case
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for (int currPos = n - 1; currPos >= 0; currPos--) {
            for (int currLane = 1; currLane <= 3; currLane++) {
                if (obstacles[currPos + 1] != currLane) {
                    dp[currLane][currPos] = dp[currLane][currPos + 1]; // move forward
                } else {
                    int ans = 1e9;
                    // try side jumps
                    for (int i = 1; i <= 3; i++) {
                        if (currLane != i && obstacles[currPos] != i) {
                            ans = min(ans, 1 + dp[i][currPos + 1]);
                        }
                    }
                    dp[currLane][currPos] = ans;
                }
            }
        }

        return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0])); // return the min side jumps from start
    }

    // solveSpace is used to solve using space optimization.
    int solveSpace(vector<int> &obstacles) {
        int n = obstacles.size() - 1;
        vector<int> curr(4); // current position values for all 3 lanes
        vector<int> next(4, 0); // next step initialized to 0 as base case

        for (int currPos = n - 1; currPos >= 0; currPos--) {
            for (int currLane = 1; currLane <= 3; currLane++) {
                if (obstacles[currPos + 1] != currLane) {
                    curr[currLane] = next[currLane]; // move forward
                } else {
                    int ans = 1e9;
                    // try side jump
                    for (int i = 1; i <= 3; i++) {
                        if (currLane != i && obstacles[currPos] != i) {
                            ans = min(ans, 1 + next[i]);
                        }
                    }
                    curr[currLane] = ans;
                }
            }
            next = curr; // shift to next
        }

        return min(next[2], min(1 + next[1], 1 + next[3])); // initial position is lane 2
    }

    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();

        // 1. Recursive
        // return solveRecu(obstacles, 2, 0);

        // 2. Memoization
        // vector<vector<int>> dp(4, vector<int>(n, -1));
        // return solveMemo(obstacles, 2, 0, dp);

        // 3. Tabulation
        // return solveTab(obstacles);

        // 4. Space Optimization
        return solveSpace(obstacles);
    }
};

// Main function for testing
int main() {
    Solution sol;

    vector<int> obstacles1 = {0, 1, 2, 3, 0};
    cout << "Test 1 - Min side jumps: " << sol.minSideJumps(obstacles1) << endl;

    vector<int> obstacles2 = {0, 1, 1, 3, 3, 0};
    cout << "Test 2 - Min side jumps: " << sol.minSideJumps(obstacles2) << endl;

    vector<int> obstacles3 = {0, 2, 1, 0, 3, 0};
    cout << "Test 3 - Min side jumps: " << sol.minSideJumps(obstacles3) << endl;

    return 0;
}





/*


🧠 Summary of Approaches:
Approach	                Time Complexity	                            Space Complexity	            Notes

Recursive	                Exponential	O(1)	                                                        Brute force, slow for large input
Memoization             	O(n × 3)	                                    O(n × 3)	                Fast and avoids recomputation
Tabulation	                O(n × 3)	                                    O(n × 3)	                Iterative, easier to debug
Space Optimized	            O(n × 3)	                                    O(3 × 2) = O(1)	            Most efficient in space


*/