#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

	int longSubarrWthSumDivByK(int arr[], int n, int k) {
	    
	    
    unordered_map<int, int> remainderIndex;
    
    int currentSum = 0;
    int maxLength = 0;
    
    for (int i = 0; i < n; i++) {
        currentSum += arr[i];
        
        int currentRemainder = ((currentSum % k) + k) % k; // To handle negative remainders
        
        if (currentRemainder == 0) {
            maxLength = i + 1;
        }
        
        else if (remainderIndex.find(currentRemainder) != remainderIndex.end()) {
            maxLength = max(maxLength, i - remainderIndex[currentRemainder]);
        }
        
        else {
            remainderIndex[currentRemainder] = i;
        }
    }
    
    return maxLength;
}


/*
Given an array arr containing N integers and a positive integer K, find the length of the longest sub array with sum of the elements divisible by the given value K.

Example 1:

Input:
N = 6, K = 3
arr[] = {2, 7, 6, 1, 4, 5}
Output: 
4
Explanation:
The subarray is {7, 6, 1, 4} with sum 18, which is divisible by 3.
Example 2:

Input:
N = 7, K = 3
arr[] = {-2, 2, -5, 12, -11, -1, 7}
Output: 
5
Explanation:
The subarray is {2,-5,12,-11,-1} with sum -3, which is divisible by 3.
Your Task:
The input is already taken care of by the driver code. You only need to complete the function longSubarrWthSumDivByK() that takes an array arr, sizeOfArray n and a  positive integer K, and returns the length of the longest subarray which has sum divisible by K. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
*/