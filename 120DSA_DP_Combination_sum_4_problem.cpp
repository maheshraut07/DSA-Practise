/*
codestudio question - Combination Sum IV

You are given an array of distinct integers and you have to tell how many different ways of selecting the elements from the array are there such that the sum of chosen elements is equal to the target number tar.

Note: Two ways are considered the same if for every index the contents of both the ways are equal example way1=[1,2,3,1] and way2= [1,2,3,1] both way1 and way 2 are the same.

But if way1 =[1,2,3,4] and way2= [4,3,2,1] then both ways are different.

Input is given such that the answer will fit in a 32-bit integer. For Example:
If N = 3 and tar = 5 and array elements are [1,2,5] then the number of possible ways of making sum = 5 are:
(1,1,1,1,1)
(1,1,1,2)
(1,2,1,1)
(2,1,1,1)
(1,1,2,1)
(2,2,1)
(1,2,2)
(2,1,2)
(5)
Hence the output will be 9.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 200
1 <= nums[i] <= 1000
All the elements will be unique
1 <= tar <= 1000

Time limit: 1 sec
Sample Input 1 :
2
3 5
1 2 5
2 3
1 2
Sample output 1 :
9
3
Explanation For Sample Output 1:
For the first test case, the number of possible ways will be
(1,1,1,1,1)
(1,1,1,2)
(1,2,1,1)
(2,1,1,1)
(1,1,2,1)
(2,2,1)
(1,2,2)
(2,1,2)
(5)

For the second test case, the number of ways will be
(1,1,1)
(1,2)
(2,1)
Here you can see we have considered (1,2) and (2,1) in 2 different ways.
Sample Input 2 :
2
3 4
12 1 3
2 41
2 34
Sample output 2 :
3
0



*/

#include <bits/stdc++.h> 
using namespace std;

int solveRecu(vector<int> &num, int target){

    if(target == 0) return 1;
    if(target < 0) return 0;

    int ans = 0;

    for(int i = 0; i < num.size(); i++){
        ans += solveRecu(num, target - num[i]);
    }

    return ans ;
}


int solveMemo(vector<int> &num, int target, vector<int> &dp){
    
    if(target == 0) return 1;
    if(target < 0) return 0;

    if(dp[target] != -1) return dp[target];

    int ans = 0;
    for(int i = 0; i < num.size(); i++){
        ans += solveMemo(num, target - num[i], dp);
    }

    dp[target] = ans;

    return dp[target];
}

int solveTab(vector<int> &num, int target){

    vector<int> dp(target+1, 0);

    dp[0] = 1;

    // traversing on target array from 1 to target
    for(int i = 1; i <= target; i++){

        // traversing on num array from 0 to size of the num array 
        for(int j = 0; j < num.size(); j++){
            if(i - num[j] >= 0) dp[i] += dp[i - num[j]];
        }
        
    }

    return dp[target];
}


int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    // return solveRecu(num, tar);

    // vector<int> dp (tar+1, -1);
    // return solveMemo(num, tar, dp);

    return solveTab(num, tar);
}


/*



✅ Dry Run (Example):
Let's say num = [1, 2], target = 3.

Initialization:
dp = [1, 0, 0, 0]

Steps:

t = 1:
dp[1] += dp[0] using 1 → dp[1] = 1

t = 2:
dp[2] += dp[1] using 1 → dp[2] = 1
dp[2] += dp[0] using 2 → dp[2] = 2

t = 3:
dp[3] += dp[2] using 1 → dp[3] = 2
dp[3] += dp[1] using 2 → dp[3] = 3

➡ Final dp = [1, 1, 2, 3]

Answer: dp[3] = 3 (ways: 1+1+1, 1+2, 2+1)

🧠 Time & Space Complexity:
Time: O(target × N)

Space: O(target)

    





*/