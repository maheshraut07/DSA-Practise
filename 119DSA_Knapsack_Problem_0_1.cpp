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