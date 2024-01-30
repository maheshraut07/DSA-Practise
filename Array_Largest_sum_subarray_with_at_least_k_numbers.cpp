// C++ program to find largest subarray sum with
// at-least k elements in it.
#include<bits/stdc++.h>
using namespace std;
 
// Returns maximum sum of a subarray with at-least
// k elements.

int main()
{
    long long a[5] = {1, 2, 3, -10, -3};
    int k = 4;
    int n = sizeof(a)/sizeof(a[0]);
    int sum =  maxSumWithK(a, n, k);

    return 0;
}


long long int maxSumWithK(long long int a[], long long int n, long long int k) 
{
    long long int maxSum[n];
    maxSum[0] = a[0];

    long long int curr_max = a[0];
    for (long long int i = 1; i < n; i++)
    {
        curr_max = max(a[i], curr_max + a[i]);
        maxSum[i] = curr_max;
    }

    long long int sum = 0;
    for (long long int i = 0; i < k; i++)
        sum += a[i];

    long long int result = sum;
    for (long long int i = k; i < n; i++)
    {
        sum = sum + a[i] - a[i - k];
        result = max(result, sum);
        result = max(result, sum + maxSum[i - k]);
    }
    return result;
}

/*
Let's use the following values for the dry run:

cpp
Copy code
long long int a[] = {1, 2, 3, -10, -3};
long long int k = 4;
long long int n = sizeof(a) / sizeof(a[0]);
Initialize maxSum array and curr_max variable.

maxSum: [1, 0, 0, 0, 0]
curr_max: 1
Loop through the array using Kadane's algorithm to fill the maxSum array.

i=1: curr_max = max(2, 1 + 2) = 3, maxSum: [1, 3, 0, 0, 0]
i=2: curr_max = max(3, 3 + 3) = 6, maxSum: [1, 3, 6, 0, 0]
i=3: curr_max = max(-10, 6 - 10) = -4, maxSum: [1, 3, 6, -4, 0]
i=4: curr_max = max(-3, -4 - 3) = -3, maxSum: [1, 3, 6, -3, 0]
Calculate the sum of the first k elements (sum): 1 + 2 + 3 - 10 = -4.

Initialize result with the value of sum: result = -4.

Loop through the array from k to n-1 to apply the sliding window technique.

i=4:
sum = -4 + (-3) - 1 = -8
result = max(-4, -8) = -4
result = max(-4, -8 + maxSum[4 - 4]) = -4
The final result is -4.
Return the result: -4.

So, the output of the given code with the provided values is -4.*/