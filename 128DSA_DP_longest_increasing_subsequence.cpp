/*
geeks for geeks     

Longest Increasing Subsequence
Difficulty: MediumAccuracy: 32.8%Submissions: 342K+Points: 4
Given an array arr[] of non-negative integers, the task is to find the length of the Longest Strictly Increasing Subsequence (LIS).

A subsequence is strictly increasing if each element in the subsequence is strictly less than the next element.

Examples:

Input: arr[] = [5, 8, 3, 7, 9, 1]
Output: 3
Explanation: The longest strictly increasing subsequence could be [5, 7, 9], which has a length of 3.
Input: arr[] = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
Output: 6
Explanation: One of the possible longest strictly increasing subsequences is [0, 2, 6, 9, 13, 15], which has a length of 6.
Input: arr[] = [3, 10, 2, 1, 20]
Output: 3
Explanation: The longest strictly increasing subsequence could be [3, 10, 20], which has a length of 3.
Constraints:
1 ≤ arr.size() ≤ 103
0 ≤ arr[i] ≤ 106


*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solveRecu(vector<int> &arr, int curr, int prev){
    // base case 
    if(curr == arr.size())
        return 0;
        
    // include 
    int include = 0; 
    if(prev == -1 || arr[curr] > arr[prev])
        include = 1 + solveRecu(arr, curr + 1, curr); // add 1 to calculate the length 
    
    
    // execlude 
    int execlude = 0 + solveRecu(arr, curr + 1, prev);
    
    return max(include, execlude);
}

int solveMemo(vector<int> &arr, int curr, int prev, vector<vector<int>> &dp){
    if(curr == arr.size())
        return 0;
        
    if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
    
    // include 
    
    int include = 0; 
    if(prev == -1 || arr[curr] > arr[prev])
        include = 1 + solveMemo(arr, curr + 1, curr, dp); // add 1 to calculate the length 
    
    
    // execlude 
    int execlude = 0 + solveMemo(arr, curr + 1, prev, dp);
    
    return dp[curr][prev+1] = max(include, execlude); // because initially thers is prev = -1 to avoid the array out of index 
}

int solveTab(vector<int> &arr, int curr, int prev){
    int n = arr.size();
    vector<vector<int>> dp(n+1 , vector<int>(n+1, 0));
    
    for(int curr = n -1 ; curr >= 0; curr--){
        for(int prev = curr -1; prev >= -1; prev --){
            
             // include
             int include = 0; 
             if(prev == -1 || arr[curr] > arr[prev])
                include = 1 + dp[curr + 1][curr + 1]; // add 1 to calculate the length 
            
            
             // execlude 
             int execlude = 0 + dp[curr + 1][prev + 1];
            
             dp[curr][prev+1] = max(include, execlude); // because initially thers is prev = -1 to avoid the array out of index 
                    
        }
    }
    
    return dp[0][0];
    
}

int solveSpace(vector<int> &arr, int curr, int prev){
    int n = arr.size();
    
    vector<int> currRow (n+1, 0);
    vector<int> nextRow (n+1, 0);
    
    for(int curr = n -1 ; curr >= 0; curr--){
        for(int prev = curr -1; prev >= -1; prev --){
            
             // include
             int include = 0; 
             if(prev == -1 || arr[curr] > arr[prev])
                include = 1 + nextRow[curr + 1]; // add 1 to calculate the length 
            
            
             // execlude 
             int execlude = 0 + nextRow[prev + 1];
            
             currRow[prev+1] = max(include, execlude); // because initially thers is prev = -1 to avoid the array out of index 
                    
        }
        
        nextRow = currRow ;
    }
    
    return nextRow[0];
    
}

int lis(vector<int>& arr) {
    // code here
    // return solveRecu(arr,0, -1 );
    
    // int n = arr.size();
    // vector<vector<int>> dp (n, vector<int>(n+1, -1));
    // return solveMemo(arr, 0, -1, dp);
    
    // return solveTab(arr, 0, -1);
    return solveSpace(arr, 0, -1);
}

int main() {
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << lis(arr) << endl;
    return 0;
}
