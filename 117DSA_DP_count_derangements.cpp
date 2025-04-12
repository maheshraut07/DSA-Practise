/*
Codestudio Question - Count derangements

Problem statement
A Derangement is a permutation of ‘N’ elements, such that no element appears in its original position. For example, an instance of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, because 2 present at index 0 is not at its initial position which is 2 and similarly for other elements of the sequence.

Given a number ‘N’, find the total number of derangements possible of a set of 'N’ elements.

Note:
The answer could be very large, output answer %(10 ^ 9 + 7).
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
1 <= N <= 3000

Time limit: 1 sec
Sample Input 1:
2
2
3
Sample Output 1:
1
2
Explanation of Sample Output 1:
In test case 1, For two elements say {0, 1}, there is only one possible derangement {1, 0}. 1 is present at index 0 and not at its actual position, that is, 1. Similarly, 0 is present at index 1 and not at its actual position, that is, 0.

In test case 2, For three elements say {0, 1, 2}, there are two possible derangements {2, 0, 1} and {1, 2, 0}. In both the derangements, no element is present at its actual position.

Sample Input 2:
2
1
4
Sample Output 2:
0
9
Explanation of Sample Output 2:
In test case 1, For the array = {0}, there is no possible derrangements. Hence the answer is 0 (zero).

In test case 2, For the array elements = {0, 1, 2, 3}, total 9 derrangements are possible. One of them is: { 3, 2, 1, 0}.


*/
#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

long long int solveRec(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;

    return ((n - 1) * ((solveRec(n - 1) % MOD) + (solveRec(n - 2) % MOD)) % MOD) % MOD;
}

long long int solveMemo(int n, std::vector<long long int> &dp) {
    if (n == 1) return 0;
    if (n == 2) return 1;

    if (dp[n] != -1) return dp[n];

    return dp[n] = ((n - 1) * ((solveMemo(n - 1, dp) % MOD) + (solveMemo(n - 2, dp) % MOD)) % MOD) % MOD;
}

long long int solveTab(int n) {
    vector<long long int> dp(n + 1, -1);

    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++) {  // Fixed loop condition
        long long int  first = dp[i - 1] % MOD;
        long long int  second = dp[i - 2] % MOD;
        long long int  sum =  (first + second) % MOD;

        dp[i] = ((i - 1) * sum ) % MOD;  // Fixed formula
    }

    return dp[n];
}

long long int solveSpace(int n) {
   
    long long int prev2  = 0;
    long long int prev1  = 1;

    for (int i = 3; i <= n; i++) {  // Fixed loop condition
        long long int  first = prev2 % MOD;
        long long int  second = prev1 % MOD;
        long long int  sum =  (first + second) % MOD;

        long long int ans = ((i - 1) * sum ) % MOD;  // Fixed formula

        prev2 = prev1;
        prev1 = ans; 
    }

    return prev1;
}

long long int countDerangements(int n) {
    // return solveRec(n);

    // std::vector<long long int> dp(n + 1, -1);
    // return solveMemo(n, dp);

    // return solveTab(n);
    return solveSpace(n);
}


