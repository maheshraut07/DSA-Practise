/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        int dp[n][m];

        for(int i = 0; i < m ; i++){
            dp[n-1][i] = matrix[n-1][i];
        }

        for(int i = n -2; i > -1; i--){
            for(int j = 0; j < m; j++){

                int best = dp[i+1][j];

                if(j > 0){
                    best = min(dp[i+1][j-1], best);
                }

                if(j < n -1){
                    best = min(dp[i+1][j+1], best);
                }

                dp[i][j] = best + matrix[i][j];
            }

        }

        return *min_element(dp[0], dp[0] + m);
        
    }