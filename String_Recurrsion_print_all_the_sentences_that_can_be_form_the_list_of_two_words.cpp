/*

Given a list of word lists of size  M * N. The task is to return all sentences possible taking one word from a list at a time via recursion. 

Example 1:
Input:

L = {{"you", "we"},
     {"have", "are"},
Output: 
{{you have}
{you are}
{we have}
{we are}}
Explanation:
Consider every every word from the list and form
sentences with every other words, taking one word from a list .

Note: You need to maintain the order of the sentences.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function sentences() which takes a matrix of strings as input and returns a matrix of string containing all possible sentences.

Expected Time Complexity: O(MN)
Expected Auxiliary Space: O(MN)

 

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}


 void solve(vector<vector<string>> &ans,vector<string>&current,  vector<vector<string>> & list,int n, int m,int row){
        if(row == n ){
        ans.push_back(current);
        return;
        }
        
        for(int i = 0; i < m; i++){ 
            current.push_back(list[row][i]);
            solve(ans, current, list, n, m , row+1);  
        
            //backtrack to remove the first word from the next row  and to add the second word from the next row 
            current.pop_back(); 
        }
    }
    vector<vector<string>> sentences(vector<vector<string>>&list){
        //Write your code here
        
        vector<vector<string>>ans;
        vector<string> current;
        int n = list.size();
        int m = list[0].size();
        solve(ans,current, list,n,m,0 );
        return ans;
    }