/*

There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

 

Example 1:


Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6
Example 2:


Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        // create the dp array to solve the answer
        long long dp[n][m][maxMove+1];

        // x and y direction array for navigating the position 
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};

        const int mod = 1e9 + 7;

        // for all the base cases setting of dp[i][j][0] = 0;

        for(int i= 0; i < n ; i ++){      // base case  
            for(int j = 0; j < n; j++){
                dp[i][j][0] = 0;
            }
        }

        // function for checking that particular position is inside the grid or not 

        auto inside = [&](int x, int y) -> bool{    // by using lambda function 
            if(x < 0 or x >= n or y < 0 or y >= m) return 0;
            return 1;
        };

        // updating the dp for next move

        for(int k = 0; k < maxMove + 1; k++){
            for(int i = 0; i < n ;i ++){
                for(int j = 0; j < m; j++){
                    dp[i][j][k] = 0;

                    for(int d = 0 ; d < 4; d++){
                        int nx = i + dx[d];
                        int ny = j + dy[d];

                        if(inside(nx,ny)){
                            dp[i][j][k] = (dp[i][j][k] + dp[nx][ny][k-1]) % mod;
                        }
                        else{
                            dp[i][j][k] = (dp[i][j][k] + 1) % mod;
                        }
                    }
                }
            }
        }

         


        return dp[startRow] [startColumn][maxMove];
        
    }