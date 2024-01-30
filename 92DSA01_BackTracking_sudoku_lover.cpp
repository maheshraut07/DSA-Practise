#include <bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

bool isSafe(int row, int col,vector<vector<int>> &board, int val ){
    int n = board[0].size();

    for(int i = 0; i < n; i++){
        // row check
        if(board[row][i] == val) return false;
        
        // column check
        if(board[i][col] == val) return false;

        //3*3 matrix check
        if(board[3*(row/3)+i/3] [3 *(col/3) + i%3] == val) return false;
    }

    return true;
}

bool solve(vector<vector<int>> &board) {
    int n = board[0].size();

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            
            // if cell is empty
            if (board[row][col] == 0) {
                for (int val = 1; val <= 9; val++) {
                    if (isSafe(row, col, board, val)) {
                        board[row][col] = val;

                        // recursive call 
                        bool aageKaSolutionPossible = solve(board);

                        if (aageKaSolutionPossible) return true;
                        else {
                            // backtrack
                            board[row][col] = 0;
                        }
                    }
                }

                // If no valid value is found for the current cell, backtrack
                return false;
            }
        }
    }

    // If all cells are filled, a solution is found
    return true;
}


void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}

// codestudio