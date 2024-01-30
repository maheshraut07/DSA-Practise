#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}
class Solution {
public:

    int solve(vector<int> &cost, int n ){

        //base case

         int prev2 = cost[0];
         int prev1 = cost[1];

         int curr;

         for(int i = 2 ; i < n; i++){
            curr = cost[0] + prev1 + prev2;
            prev1 = curr;
            prev2 = prev1;
         }

         return min(prev1, prev2);



    }
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        //create dp array with initial values as -1
        //step 1 

        

       int ans = solve(cost, n);
       return ans;
        
    }
};

//using space omptimization 