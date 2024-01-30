/*
Given an array of integers. Find if there is a subarray (of size at-least one) with 0 sum. You just need to return true/false depending upon whether there is a subarray present with 0-sum or not. Printing will be taken care by the driver code.

Example 1:

Input:
n = 5
arr = {4,2,-3,1,6}
Output: 
Yes
Explanation: 
2, -3, 1 is the subarray with sum 0.
Example 2:

Input:
n = 5
arr = {4,2,0,1,6}
Output: 
Yes
Explanation: 
0 is one of the element in the array so there exist a subarray with sum 0.


*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

 bool subArrayExists(int arr[], int n)
    {
        unordered_set <int> s ;
        int preSum = 0;

        for(int i = 0; i < n; i++){
            preSum += arr[i];

            if(s.find(preSum) != s.end()) return true;   // if preSum is already in set tha means there is subarray with 0 sum
            if(preSum == 0) return true;

            s.insert(preSum);  // if sum is not present insert it into the set 
        }

        return false;
    }
