#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> & num , int n, int target){
    if(target == 0) return 0;

    if(target < 0) return INT_MAX;

    int mini = INT_MAX;

    for(int i = 0; i < n; i++){
        int ans  = solve(num , n, target - num[i]);
        if(ans != INT_MAX)  // if valid answer is found 
            mini = min(mini , 1 + ans);
    }

    return mini;
}

int main(){
    
    vector<int> num = {2,2,4};
    int n = num.size();
    int target = 8;

    int ans = solve(num , n, target);
    cout << "the minimum number of coins to make the target is : "<< ans; 

    return 0;
}

// This question is solved using recurrsion 

