/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.


*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:

    int solveRecu(string a, string b, int i , int j ){
        if(i >= a.length()) return b.length() - j; 
        if(j >= b.length()) return a.length() - i;

        int ans = 0; 
        if(a[i] == b[j]) ans = solveRecu(a, b, i + 1, j + 1);
        else{
            int insertAns = 1 + solveRecu(a, b, i, j + 1);
            int deleteAns = 1 + solveRecu(a, b, i + 1, j);
            int replaceAns = 1 + solveRecu(a, b, i + 1, j + 1);
            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        return ans; 
    }

    int solveMemo(string a, string b, int i , int j, vector<vector<int>> &dp){
        if(i >= a.length()) return b.length() - j; 
        if(j >= b.length()) return a.length() - i;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0; 
        if(a[i] == b[j]) ans = solveMemo(a, b, i + 1, j + 1, dp);
        else{
            int insertAns = 1 + solveMemo(a, b, i, j + 1, dp);
            int deleteAns = 1 + solveMemo(a, b, i + 1, j, dp);
            int replaceAns = 1 + solveMemo(a, b, i + 1, j + 1, dp);
            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        return dp[i][j] = ans; 
    }

    int solveTab(string a, string b){
        int n = a.length();
        int m = b.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 0; i <= n; i++) dp[i][m] = n - i;
        for(int j = 0; j <= m; j++) dp[n][j] = m - j;

        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                int ans = 0;
                if(a[i] == b[j]) {
                    ans = dp[i + 1][j + 1];
                } else {
                    int insertAns = 1 + dp[i][j + 1];
                    int deleteAns = 1 + dp[i + 1][j];
                    int replaceAns = 1 + dp[i + 1][j + 1];
                    ans = min({insertAns, deleteAns, replaceAns});
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0]; 
    }

    int solveSpace(string a, string b){
        int n = a.length();
        int m = b.length();

        vector<int> next(m + 1, 0);
        vector<int> curr(m + 1, 0);

        for (int j = 0; j <= m; j++) {
            next[j] = m - j;
        }

        for (int i = n - 1; i >= 0; i--) {
            curr[m] = n - i;

            for (int j = m - 1; j >= 0; j--) {
                if (a[i] == b[j]) {
                    curr[j] = next[j + 1];
                } else {
                    int insertOp = 1 + curr[j + 1];
                    int deleteOp = 1 + next[j];
                    int replaceOp = 1 + next[j + 1];
                    curr[j] = min({insertOp, deleteOp, replaceOp});
                }
            }
            next = curr;
        }

        return next[0];
    }

    int minDistance(string word1, string word2) {
        // return solveRecu(word1, word2, 0, 0);
        // vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, -1));
        // return solveMemo(word1, word2, 0, 0, dp);
        // return solveTab(word1, word2);
        return solveSpace(word1, word2);  // most optimized
    }
};

int main() {
    Solution sol;
    string word1 = "horse";
    string word2 = "ros";

    int result = sol.minDistance(word1, word2);
    cout << "Minimum number of operations to convert \"" << word1 << "\" to \"" << word2 << "\" is: " << result << endl;

    return 0;
}
