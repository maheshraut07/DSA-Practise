/*

You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.


Example 1:

Input:
n = 6
arr[] = {0,0,5,5,0,0}
Output: 6
Explanation: The 6 subarrays are 
[0], [0], [0], [0], [0,0], and [0,0].

Example 2:

Input:
n = 10
arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7}
Output: 4
Explanation: The 4 subarrays are [-1 -3 4]
[-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]



*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

 long long int findSubarray(vector<long long int>& arr, int n) {
    unordered_map<long long int, long long int> prefixSumCount; // To store prefix sum and its count
    long long int sum = 0;
    long long int totalCount = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            totalCount++;
        }

        if (prefixSumCount.find(sum) != prefixSumCount.end()) {  // if the sum is already present in the map  that means there exits subarray with 0 sum
                                                                 // so update the totalcount by the number according to the count of that sum
            totalCount += prefixSumCount[sum];
        }

        prefixSumCount[sum]++;       // we have to increase that count of the sum every time 
    }

    return totalCount;
}