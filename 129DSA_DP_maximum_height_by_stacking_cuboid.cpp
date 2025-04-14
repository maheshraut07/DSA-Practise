/*
LEETCODE
1691. Maximum Height by Stacking Cuboids 
Hard
Topics
Companies
Hint
Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other.

You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

Return the maximum height of the stacked cuboids.

 

Example 1:



Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
Output: 190
Explanation:
Cuboid 1 is placed on the bottom with the 53x37 side facing down with height 95.
Cuboid 0 is placed next with the 45x20 side facing down with height 50.
Cuboid 2 is placed next with the 23x12 side facing down with height 45.
The total height is 95 + 50 + 45 = 190.
Example 2:

Input: cuboids = [[38,25,45],[76,35,3]]
Output: 76
Explanation:
You can't place any of the cuboids on the other.
We choose cuboid 1 and rotate it so that the 35x3 side is facing down and its height is 76.
Example 3:

Input: cuboids = [[7,11,17],[7,17,11],[11,7,17],[11,17,7],[17,7,11],[17,11,7]]
Output: 102
Explanation:
After rearranging the cuboids, you can see that all cuboids have the same dimension.
You can place the 11x7 side down on all cuboids so their heights are 17.
The maximum height of stacked cuboids is 6 * 17 = 102.
 

Constraints:

n == cuboids.length
1 <= n <= 100
1 <= widthi, lengthi, heighti <= 100





*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Check if newBox can be placed on top of base
    bool check(vector<int> base, vector<int> newBox) {
        return newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2];
    }

    // Dynamic Programming logic using space optimization
    int solveSpace(vector<vector<int>> &arr) {
        int n = arr.size();
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                int include = 0;
                if (prev == -1 || check(arr[curr], arr[prev]))
                    include = arr[curr][2] + nextRow[curr + 1];

                int exclude = 0 + nextRow[prev + 1];

                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }

        return nextRow[0];
    }

    // Main function to calculate maximum height
    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto &a : cuboids) {
            sort(a.begin(), a.end()); // Step 1: Sort dimensions of each cuboid
        }

        sort(cuboids.begin(), cuboids.end()); // Step 2: Sort all cuboids

        return solveSpace(cuboids); // Step 3: Apply LIS logic
    }
};

// Driver code
int main() {
    Solution sol;

    // Example cuboids: each cuboid is {width, length, height}
    vector<vector<int>> cuboids = {
        {50, 45, 20},
        {95, 37, 53},
        {45, 23, 12}
    };

    int result = sol.maxHeight(cuboids);
    cout << "Maximum height of stackable cuboids: " << result << endl;

    return 0;
}


