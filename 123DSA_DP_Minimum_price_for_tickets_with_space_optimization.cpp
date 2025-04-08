/*


Problem statement
Ninja is willing to take some time off from his training and planning a year-long tour. You are given a DAYS array consisting of ‘N’ days when Ninjas will be traveling during the year. Each Day is an integer between 1 to 365 (both inclusive). Train tickets are sold in three different ways:
A 1-day pass is sold for 'COST'[0] coins,
A 7-day pass is sold for 'COST'[1] coins, and
A 30-day  pass is sold for 'COST'[2] coins.
The passes allow for many days of consecutive travel.
Your task is to help the Ninja to find the minimum number of coins required to complete his tour. For example,
If Ninja gets a 7-day pass on day 2, then he can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 365
1 <= DAYS[i] <= 365

Time Limit: 1 sec
Sample Input 1:
2
2 
2 5
1 4 25    
7
1 3 4 5 7 8 10
2 7 20
Sample Output 1:
2
11
Explanation For sample input 1:
For the first test case, 
On Day 2, Ninja will buy a 1-day pass with 1 coin.
On Day 5, Ninja will buy a 1-day pass with 1 coin.
In total, Ninja will spend 2 coins. Hence the answer is 2.

For the second test case,
On Day 1, Ninja will buy a 1-day pass with 2 coins.
On Day 3, Ninja will buy a 7-day pass with 7 coins valid for days 3,4,5...9.
On Day 10, Ninja will buy a 1-day pass with 2 coins.
In total, Ninja will spend 11 coins. Hence the answer is 11.
Sample Input 2:
2
6
1 4 6 7 8 20
2 7 15
12
1 2 3 4 5 6 7 8 9 10 30 31
2 7 15 
Sample Output 2:
11
17*/


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursion
int solveRecu(int n, vector<int> &days, vector<int> &cost, int index) {
    if (index >= n) return 0;

    // 1-day pass
    int option1 = cost[0] + solveRecu(n, days, cost, index + 1);

    // 7-day pass
    int i;
    for (i = index; i < n && days[i] < days[index] + 7; i++);
    int option2 = cost[1] + solveRecu(n, days, cost, i);

    // 30-day pass
    for (i = index; i < n && days[i] < days[index] + 30; i++);
    int option3 = cost[2] + solveRecu(n, days, cost, i);

    return min(option1, min(option2, option3));
}

// Memoization
int solveMemo(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp) {
    if (index >= n) return 0;
    if (dp[index] != -1) return dp[index];

    // 1-day pass
    int option1 = cost[0] + solveMemo(n, days, cost, index + 1, dp);

    // 7-day pass
    int i;
    for (i = index; i < n && days[i] < days[index] + 7; i++);
    int option2 = cost[1] + solveMemo(n, days, cost, i, dp);

    // 30-day pass
    for (i = index; i < n && days[i] < days[index] + 30; i++);
    int option3 = cost[2] + solveMemo(n, days, cost, i, dp);

    return dp[index] = min(option1, min(option2, option3));
}

// Tabulation
int solveTab(int n, vector<int> &days, vector<int> &cost) {
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;

    for (int k = n - 1; k >= 0; k--) {
        // 1-day pass
        int option1 = cost[0] + dp[k + 1];

        // 7-day pass
        int i;
        for (i = k; i < n && days[i] < days[k] + 7; i++);
        int option2 = cost[1] + dp[i];

        // 30-day pass
        for (i = k; i < n && days[i] < days[k] + 30; i++);
        int option3 = cost[2] + dp[i];

        dp[k] = min(option1, min(option2, option3));
    }

    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost) {
    // Method 1: Recursion
    // return solveRecu(n, days, cost, 0);

    // Method 2: Memoization
    // vector<int> dp(n + 1, -1);
    // return solveMemo(n, days, cost, 0, dp);

    // Method 3: Tabulation
    return solveTab(n, days, cost);
}

int main() {
    // Sample Input
    int n = 6;
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> cost = {2, 7, 15};

    cout << "Using Recursion: " << solveRecu(n, days, cost, 0) << endl;

    vector<int> dp(n + 1, -1);
    cout << "Using Memoization: " << solveMemo(n, days, cost, 0, dp) << endl;

    cout << "Using Tabulation: " << solveTab(n, days, cost) << endl;

    return 0;
}
/*


Problem statement
Ninja is willing to take some time off from his training and planning a year-long tour. You are given a DAYS array consisting of ‘N’ days when Ninjas will be traveling during the year. Each Day is an integer between 1 to 365 (both inclusive). Train tickets are sold in three different ways:
A 1-day pass is sold for 'COST'[0] coins,
A 7-day pass is sold for 'COST'[1] coins, and
A 30-day  pass is sold for 'COST'[2] coins.
The passes allow for many days of consecutive travel.
Your task is to help the Ninja to find the minimum number of coins required to complete his tour. For example,
If Ninja gets a 7-day pass on day 2, then he can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 365
1 <= DAYS[i] <= 365

Time Limit: 1 sec
Sample Input 1:
2
2 
2 5
1 4 25    
7
1 3 4 5 7 8 10
2 7 20
Sample Output 1:
2
11
Explanation For sample input 1:
For the first test case, 
On Day 2, Ninja will buy a 1-day pass with 1 coin.
On Day 5, Ninja will buy a 1-day pass with 1 coin.
In total, Ninja will spend 2 coins. Hence the answer is 2.

For the second test case,
On Day 1, Ninja will buy a 1-day pass with 2 coins.
On Day 3, Ninja will buy a 7-day pass with 7 coins valid for days 3,4,5...9.
On Day 10, Ninja will buy a 1-day pass with 2 coins.
In total, Ninja will spend 11 coins. Hence the answer is 11.
Sample Input 2:
2
6
1 4 6 7 8 20
2 7 15
12
1 2 3 4 5 6 7 8 9 10 30 31
2 7 15 
Sample Output 2:
11
17*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solveSpaceOpt(int n, vector<int> days, vector<int> cost) {
    queue<pair<int, int>> week, month;
    int ans = 0;

    for (int day : days) {
        // Remove expired 7-day and 30-day passes
        while (!week.empty() && week.front().first + 7 <= day)
            week.pop();
        while (!month.empty() && month.front().first + 30 <= day)
            month.pop();

        // Add new 7-day and 30-day pass
        week.push(make_pair(day, ans + cost[1]));
        month.push(make_pair(day, ans + cost[2]));

        // Calculate minimum cost among all options
        ans = min(ans + cost[0], min(week.front().second, month.front().second));
    }

    return ans;
}

int main() {
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> cost = {2, 7, 15};

    int n = days.size();
    int result = solveSpaceOpt(n, days, cost);

    cout << "Minimum cost of travel is: " << result << endl;

    return 0;
}


/*


✅ What This Code Does
This space-optimized solution solves the problem of finding the minimum cost of travel when you can choose between:

1-day pass → cost[0]

7-day pass → cost[1]

30-day pass → cost[2]

You're given a list of days you plan to travel (days[]) and need to cover all of them at minimum cost, possibly using overlapping passes.

✅ Code Walkthrough
🔸Variables:
cpp
Copy
Edit
queue<pair<int, int>> week, month;
int ans = 0;
week → tracks all valid 7-day passes and their costs.

month → tracks all valid 30-day passes and their costs.

ans → stores the minimum cost up to the current day.

🔸Iterate over each travel day:
cpp
Copy
Edit
for (int day : days)
We go through each travel day one by one.

🔸Step 1: Remove expired passes
cpp
Copy
Edit
while (!week.empty() && week.front().first + 7 <= day) week.pop();
while (!month.empty() && month.front().first + 30 <= day) month.pop();
We remove any 7-day or 30-day passes that can no longer cover the current day.

For example, if today is day 10, and a pass started on day 1, it expired already.

🔸Step 2: Add new 7-day and 30-day pass starting today
cpp
Copy
Edit
week.push(make_pair(day, ans + cost[1]));
month.push(make_pair(day, ans + cost[2]));
We consider the cost of buying a new pass starting today.

The new cost is ans + cost[i] because you already spent ans to reach this day.

🔸Step 3: Calculate minimum of 1-day, 7-day, or 30-day
cpp
Copy
Edit
ans = min(ans + cost[0], min(week.front().second, month.front().second));
You have 3 choices:

Buy a 1-day pass today.

Use the cheapest valid 7-day pass from the queue.

Use the cheapest valid 30-day pass from the queue.

✅ How It's Different from Previous Solutions
Feature	Recursive / Memo / Tabular	Space Optimized (This One)
✅ Uses Recursion	Yes (in solveRecu and solveMemo)	❌ No recursion
✅ Uses DP array	Yes (dp[] array used in memo/tabulation)	❌ No DP array
✅ Uses Queues	❌ No queues	✅ Two queues used to track valid pass windows
✅ Time Complexity	O(n) after memoization	O(n)
✅ Space Complexity	O(n) due to DP array	✅ O(1) or O(n) (small due to queue size)
✅ Real-Time Simulation	❌ Not directly	✅ Simulates real-time decision making
✅ Summary
This approach uses sliding windows (via queues) to only keep track of valid passes.

It avoids extra memory like recursion stack or full DP array.

It's clean, intuitive, and great when days are sparse (not every day is a travel day).

*/