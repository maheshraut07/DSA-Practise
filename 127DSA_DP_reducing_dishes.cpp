/*
LEETCODE 
1402. Reducing Dishes

Hard
Topics
Companies
Hint

A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

 

Example 1:

Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.
Example 2:

Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
Example 3:

Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People do not like the dishes. No dish is prepared.
 

Constraints:

n == satisfaction.length
1 <= n <= 500
-1000 <= satisfaction[i] <= 1000


 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    
    int solveRecu(vector<int> &satisfaction, int index, int time){
        //base case 
        int n = satisfaction.size();
        if(index >= n) return 0;

        // include the element in the ans with adding the satisfaction factor 
        int include = satisfaction[index] * (time + 1) + solveRecu(satisfaction, index +1, time + 1);

        // execlude that element but increase the index time will remain constant 
        int execlude = 0 + solveRecu(satisfaction, index + 1, time );

        // we want the maximum result based on the satisfaction factor 
        return max(include, execlude);
    }

    int solveMemo(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp){
        int n = satisfaction.size();
        if(index >= n) return 0;

        // step 3 : if the result for that overlapping subproblem already solved and stored in the dp array, if yes return that value 
        if(dp[index][time] != -1) return dp[index][time];

        int include = satisfaction[index] * (time + 1) + solveMemo(satisfaction, index + 1, time + 1, dp);
        int execlude = 0 + solveMemo(satisfaction, index+1, time, dp);
        
        //step 2 : store the answer in the dp array before returning it to i.e. memoization 
        return dp[index][time] = max(include, execlude);
    }

    int solveTab(vector<int> &satisfaction){
        int n = satisfaction.size();

        // stpes to convert memoization (top down) approach to tabulation(bottom up approach )
        // step 1 : create dp array based on the parameters 
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        // step 2 : analyase the base case and store the result to fill the array dp array 
        // no need to analyse the base case in the recurrsive function and storing the result fo fill the vector
        // bacuase in the recurrsive base case we are returninng the 0 and in dp array we are already initializing the array with the 0 values

        // step 3 : use for loops and convert the recurrsive calls into indexing based dp values 
        for(int index = n-1; index >= 0 ; index --){
            for(int time = index; time >= 0; time--){
                int include = satisfaction[index] * (time + 1) + dp[index + 1] [time + 1];
                int execlude = 0 + dp[index + 1] [time];

                dp[index][time] = max(include, execlude);
            }
        }

        //here we are going botton to top hence tabulation ( n to 0 )
        //hence answer will be storing at the 0,0 index of the dp array 
        return dp[0][0];
    }

    int solveSpace(vector<int> &satisfaction){
        // to covert the tabulization solution into spaceOptimaztion solution 
        // try to analyse the dependency of the dp array if it's fixed like (dp[index][time] = dp[index -1][index-1]) then it can be coverted into space optimization 

        // here the result is depend on the next row and next column 
        // i.e. dp[index][time] is depenedent on the dp[index + 1][time + 1] and dp[index + 1][time]

        // hence solution can be build by using just two array 
        int n = satisfaction.size();

        vector<int> curr (n+1, 0);
        vector<int> next (n+1, 0);

        for(int index = n-1; index >= 0; index --){
            for(int time = index; time >= 0; time --){

                int include = satisfaction[index] * (time + 1) + next[time + 1 ];
                int execlude = 0 + next[time];

                curr[time] = max(include, execlude);
            }

            next = curr;
        }

        return next[0];
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        // return solveRecu(satisfaction, 0, 0);
        
        // int n = satisfaction.size();
        // steps to convert recurrsive solution into dynamic programming memoization solution 
        // step 1 : create the dp array used for the memoization 
        // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        // return solveMemo(satisfaction, 0, 0, dp);
        
        // return solveTab(satisfaction);
        return solveSpace(satisfaction);
    }
};

//--------------------- MAIN FUNCTION -----------------------

int main() {
    Solution sol;

    vector<int> satisfaction1 = {-1, -8, 0, 5, -9};
    vector<int> satisfaction2 = {4, 3, 2};
    vector<int> satisfaction3 = {-1, -4, -5};

    cout << "Example 1 Output: " << sol.maxSatisfaction(satisfaction1) << endl;  // Expected: 14
    cout << "Example 2 Output: " << sol.maxSatisfaction(satisfaction2) << endl;  // Expected: 20
    cout << "Example 3 Output: " << sol.maxSatisfaction(satisfaction3) << endl;  // Expected: 0

    return 0;
}
