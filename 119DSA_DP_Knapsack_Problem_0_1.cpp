/*

codestudio question - 0 1 Knapsack

Problem statement
A thief is robbing a store and can carry a maximum weight of ‘W’ into his knapsack. There are 'N' items available in the store and the weight and value of each item is known to the thief. Considering the constraints of the maximum weight that a knapsack can carry, you have to find the maximum profit that a thief can generate by stealing items.

Note: The thief is not allowed to break the items.

For example, N = 4, W = 10 and the weights and values of items are weights = [6, 1, 5, 3] and values = [3, 6, 1, 4]. Then the best way to fill the knapsack is to choose items with weight 6, 1 and 3. The total value of knapsack = 3 + 6 + 4 = 13.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 10^3
1 <= W <= 10^3
1<= weights <=10^3
1 <= values <= 10^3


where 'T' is the number of test cases, ‘N’ is the number of items, "weights" is the weight of each item, "values" is the value of each item and ‘W’ is the maximum weight the thief can carry. 
Sample Input:
1 
4 5
1 2 4 5
5 4 8 6
Sample Output:
13
Explanation of Sample output 1
The most optimal way to fill the knapsack is to choose items with weight 4 and value 8, weight 1 and value 5.

The total value of the knapsack =  8 + 5 = 13.
Sample Input 2:
1
5 100
20 24 36 40 42
12 35 41 25 32
Sample output 2:
101
C++ (g++ 5.4)
123456789101112131415161718192021222324252627282930313233
int solveRecu(vector<int> &values, vector<int> &weights, int index, int capacity)
{
	//we will start from right to left 
	// if there is only one weight then compare it with the maxWeight if is less than then add to the knapsack otherwise not 

	if(index == 0){
		if(weights[0] <= capacity ) return values[0];
		else return 0;
	}




*/


#include <iostream>
#include <vector>
using namespace std;

// Recursive approach (Exponential Time Complexity)
int solveRecu(vector<int> &values, vector<int> &weights, int index, int capacity)
{
    // Base Case: If there is only one weight, compare it with the maxWeight
    if (index == 0)
    {
        if (weights[0] <= capacity)
            return values[0];
        else
            return 0;
    }

    // Choice 1: Include the current item (if it fits within capacity)
    int include = 0;
    if (weights[index] <= capacity)
    {
        include = values[index] + solveRecu(values, weights, index - 1, capacity - weights[index]);
    }

    // Choice 2: Exclude the current item
    int exclude = solveRecu(values, weights, index - 1, capacity);

    // Return the maximum value possible
    return max(include, exclude);
}

// Memoization approach (Top-Down DP)
int solveMemo(vector<int> &values, vector<int> &weights, int index, int capacity, vector<vector<int>> &dp)
{
    // Base Case
    if (index == 0)
    {
        if (weights[0] <= capacity)
            return values[0];
        else
            return 0;
    }

    // If value already computed, return it
    if (dp[index][capacity] != -1)
        return dp[index][capacity];

    // Choice 1: Include the current item (if possible)
    int include = 0;
    if (weights[index] <= capacity)
    {
        include = values[index] + solveMemo(values, weights, index - 1, capacity - weights[index], dp);
    }

    // Choice 2: Exclude the current item
    int exclude = solveMemo(values, weights, index - 1, capacity, dp);

    // Store the result in dp array and return the maximum value
    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

// Tabulation approach (Bottom-Up DP)
int solveTab(vector<int> &values, vector<int> &weights, int n, int capacity)
{
    // Step 1: Create a DP table initialized with 0
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    // Step 2: Base case initialization for the first row
    for (int w = weights[0]; w <= capacity; w++)
    {
        if (weights[0] <= capacity)
            dp[0][w] = values[0];
    }

    // Step 3: Fill the DP table iteratively
    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            // Choice 1: Include the current item (if possible)
            int include = 0;
            if (weights[index] <= w)
            {
                include = values[index] + dp[index - 1][w - weights[index]];
            }

            // Choice 2: Exclude the current item
            int exclude = dp[index - 1][w];

            // Take the maximum of including or excluding
            dp[index][w] = max(include, exclude);
        }
    }

    // Return the result from the last row and last column
    return dp[n - 1][capacity];
}

// Space Optimized approach (Using two 1D arrays)
int solveSpace(vector<int> &values, vector<int> &weights, int n, int capacity)
{
    // Step 1: Create two 1D DP arrays
    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);

    // Step 2: Base case initialization for first item
    for (int w = weights[0]; w <= capacity; w++)
    {
        if (weights[0] <= capacity)
            prev[w] = values[0];
    }

    // Step 3: Compute results iteratively
    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            // Choice 1: Include the current item (if possible)
            int include = 0;
            if (weights[index] <= w)
            {
                include = values[index] + prev[w - weights[index]];
            }

            // Choice 2: Exclude the current item
            int exclude = prev[w];

            curr[w] = max(include, exclude);
        }

        // Copy current row to previous row for next iteration
        prev = curr;
    }

    return prev[capacity];
}

// Most Optimized Space approach (Using only one 1D array)
int solveSpace2(vector<int> &values, vector<int> &weights, int n, int capacity)
{
    // Step 1: Create a 1D DP array initialized to 0
    vector<int> curr(capacity + 1, 0);

    // Step 2: Base case initialization
    for (int w = weights[0]; w <= capacity; w++)
    {
        if (weights[0] <= capacity)
            curr[w] = values[0];
    }

    // Step 3: Compute results iteratively (Right to Left to avoid overwriting)
    for (int index = 1; index < n; index++)
    {
        for (int w = capacity; w >= 0; w--)
        {
            // Choice 1: Include the current item (if possible)
            int include = 0;
            if (weights[index] <= w)
            {
                include = values[index] + curr[w - weights[index]];
            }

            // Choice 2: Exclude the current item
            int exclude = curr[w];

            curr[w] = max(include, exclude);
        }
    }

    return curr[capacity];
}

// Function to find the maximum profit using different methods
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    // Recursive approach (Exponential)
    // return solveRecu(values, weights, n-1, w);

    // Memoization approach (Optimized DP)
    // vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    // return solveMemo(values, weights, n-1, w, dp);

    // Tabulation approach (Iterative DP)
    // return solveTab(values, weights, n, w);

    // Space Optimized DP (Using Two 1D arrays)
    // return solveSpace(values, weights, n, w);

    // Most Optimized DP (Using Single 1D array)
    return solveSpace2(values, weights, n, w);
}

// Driver Code
int main()
{
    vector<int> values = {60, 100, 120}; // Values of items
    vector<int> weights = {10, 20, 30};  // Weights of items
    int capacity = 50;                   // Maximum weight the knapsack can carry
    int n = values.size();                // Number of items

    // Calculate the maximum profit
    int result = maxProfit(values, weights, n, capacity);

    // Print the result
    cout << "Maximum Profit: " << result << endl;

    return 0;
}


/*
Approach

1) try the include, execlude approach 



✅ Key Features of this Code
✔ All five approaches implemented
✔ Fully commented code for easy understanding
✔ Optimized Space Complexity from O(n * capacity) → O(capacity)
✔ Tested with sample input, giving Expected Output:

yaml
Copy
Edit
Maximum Profit: 220


✅ Final Complexity Analysis


Approach	                                    Time Complexity	                                Space Complexity	                    Efficiency


Recursive	                                        O(2^n)	                                  O(n) (Recursion Stack)	                 Slowest
Memoization                                   	O(n * capacity)                            	  O(n * capacity)	                         Faster
Tabulation	                                    O(n * capacity)	                              O(n * capacity)	                        Efficient
Space Optimized (2D → 1D)	                    O(n * capacity)	                              O(capacity)	                            More Efficient
Most Optimized (Single Array)	                O(n * capacity)	                              O(capacity)	                            Best Approach 🚀



*/