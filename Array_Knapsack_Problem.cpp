/*

Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item here. 

Example 1:

Input:
N = 3, W = 50
value[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.000000
Explanation:
Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with value 120 and weight 30, to fit it into weight 20. so it becomes (120/30)*20=80, so the total weight becomes 60+100+80.0=240.0
Thus, total maximum value of item we can have is 240.00 from the given capacity of sack. 
Example 2:

Input:
N = 2, W = 50
value[] = {60,100}
weight[] = {10,20}
Output:
160.000000
Explanation:
Take both the items completely, without breaking.
Total maximum value of item we can have is 160.00 from the given capacity of sack.


*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

struct Item{
    int value;
    int weight;
};

    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,int>> items; // the first part is denoting the value per unit weight
                                        // the second part is denoting the maximum weight that i can take for a partiular category 
        
        for(int i = 0; i < n; i ++){    // find the value per weight for each item in the given arrays 
            double value_per_weight = (double)arr[i].value / (double)arr[i].weight;
            
            items.emplace_back(value_per_weight,arr[i].weight);
        }
        
        // sort the items array according to decreasing the order of value per weight for calculating the maximum weight 
        
        sort(items.begin(),items.end(),[](pair<double,int> &a, pair<double,int>&b){
            return a.first > b.first;
        });
        
        double ans = 0;
        
        // calculate the answer on the basis of first value and the second value(weight)
        
        for(int i = 0; i < n; i ++){
            
            int take_weight = min(W, items[i].second);
            W -= take_weight;
            ans += take_weight * items[i].first;
        }
        
        return ans;
    }