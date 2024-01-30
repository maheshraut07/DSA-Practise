/*
Given an array arr[] of length n. Find all possible unique permutations of the array in sorted order. A sequence A is greater than sequence B if there is an index i for which Aj = Bj for all j<i and Ai > Bi.

Example 1:

Input: 
n = 3
arr[] = {1, 2, 1}
Output: 
1 1 2
1 2 1
2 1 1
Explanation:
These are the only possible unique permutations
for the given array.
Example 2:

Input: 
n = 2
arr[] = {4, 5}
Output: 
Only possible 2 unique permutations are
4 5
5 4
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

vector<vector<int>> uniquePerms(vector<int> &arr, int n) {
     
        vector<vector<int>> ans;
        vector<int> curr;
        vector<int> taken(n, 0);

        function <void(int)> solve = [&] (int p){
           if (p == n) {
                // If we have taken all the elements, push the current vector into the main ans vector
                ans.push_back(curr);
                return;
           }
           
           vector<int> curr_taken(11,0);
        

            // Iterate over the array elements
            for (int i = 0; i < n; i++) {
                if (!taken[i] && !curr_taken[arr[i]]) {
                    taken[i] = 1;
                    curr_taken[arr[i]] = 1;
                    curr.push_back(arr[i]);

                    solve(p + 1);

                    curr.pop_back(); // Backtrack to check all combinations
                    taken[i] = 0;
                }
            }
        };

        solve(0);
        
        // Sort the answer vectors to get them in ascending order
        sort(ans.begin(), ans.end());

        return ans;
    }

