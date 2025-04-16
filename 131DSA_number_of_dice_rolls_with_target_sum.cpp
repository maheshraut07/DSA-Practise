/*

Dice throw
Difficulty: MediumAccuracy: 36.52%Submissions: 35K+Points: 4Average Time: 30m
Given n dice each with m faces. Find the number of ways to get sum x which is the summation of values on each face when all the dice are thrown.

Example:

Input: m = 6, n = 3, x = 12
Output: 25
Explanation: There are 25 total ways to get the Sum 12 using 3 dices with faces from 1 to 6.
Input: m = 2, n = 3, x = 6
Output: 1
Explanation: There is only 1 way to get the Sum 6 using 3 dices with faces from 1 to 2. All the dices will have to land on 2.
Constraints:
1 <= m,n,x <= 50


*/

#include <iostream>
#include <vector>
using namespace std;

int solveRecu(int dices, int faces, int targetSum){
    if(targetSum < 0) return 0;
    if(dices == 0 && targetSum != 0) return 0;
    if(dices != 0 && targetSum == 0) return 0;
    if(dices == 0 && targetSum == 0) return 1;

    int ans = 0; 
    for(int i = 1; i <= faces; i++){
        ans = ans + solveRecu(dices - 1 , faces, targetSum - i);
    }
    return ans; 
}

int solveMemo(int dices, int faces, int targetSum, vector<vector<int>> &dp){
    if(targetSum < 0) return 0;
    if(dices == 0 && targetSum != 0) return 0;
    if(dices != 0 && targetSum == 0) return 0;
    if(dices == 0 && targetSum == 0) return 1;
    
    if(dp[dices][targetSum] != -1) return dp[dices][targetSum];

    int ans = 0; 
    for(int i = 1; i <= faces; i++){
        ans = ans + solveMemo(dices - 1 , faces, targetSum - i, dp);
    }
    return dp[dices][targetSum] = ans; 
}

int solveTab(int dices, int faces, int targetSum){
    int n = dices;
    int x = targetSum;
    vector<vector<int>> dp(n+1, vector<int>(x+1, -1));
    
    dp[0][0] = 1;
    for(int dices = 1; dices <= n; dices++){
        for(int targetSum = 1 ; targetSum <= x; targetSum++ ){
            int ans = 0; 
            for(int i = 1; i <= faces; i++){
                if(targetSum - i >= 0)
                    ans += dp[dices - 1][targetSum - i];
            }
            dp[dices][targetSum] = ans; 
        }
    }
    return dp[dices][targetSum];
}

int solveSpace(int dices, int faces, int targetSum){
    int n = dices;
    int x = targetSum;

    vector<int> prev (x+1, 0);
    vector<int> curr (x+1, 0);
    
    prev[0] = 1;
    
    for(int dices = 1; dices <= n; dices++){
        for(int targetSum = 1 ; targetSum <= x; targetSum++ ){
            int ans = 0; 
            for(int i = 1; i <= faces; i++){
                if(targetSum - i >= 0)
                    ans += prev[targetSum - i];
            }
            curr[targetSum] = ans; 
        }
        prev = curr ;
    }
    return prev[targetSum];
}

int noOfWays(int m, int n, int x) {
    //return solveRecu(n, m, x);
    //vector<vector<int>> dp(n+1, vector<int>(x+1, -1));
    //return solveMemo(n, m, x, dp);
    //return solveTab(n, m , x);
    return solveSpace(n, m, x);
}

int main() {
    int m, n, x;
    cout << "Enter number of faces on a die (m): ";
    cin >> m;
    cout << "Enter number of dice (n): ";
    cin >> n;
    cout << "Enter target sum (x): ";
    cin >> x;

    int result = noOfWays(m, n, x);
    cout << "Number of ways to get sum " << x << " with " << n << " dice of " << m << " faces: " << result << endl;

    return 0;
}


