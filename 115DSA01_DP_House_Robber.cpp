#include<bits/stdc++.h>
using namespace std;


int solveSpaceOptimization(vector<int> &arr){

    int n = arr.size();
    
    int prev2 = 0;
    int prev1 = arr[0];
    
    for(int i = 1; i < n; i++){
        int include = prev2 + arr[i];
        int execlude = prev1 + 0;
        
        int ans = max(include, execlude);
        prev2 = prev1;
        prev1 = ans;

    }

    return prev1;


}



int findMaxSum(vector<int>&arr, int n) {   

    vector<int> excludeFirst(n);
    vector<int> excludeLast(n);

    for(int i = 0; i < n ; i++){
        if(i != 0) excludeFirst.push_back(arr[i]);
        if(i != n-1) excludeLast.push_back(arr[i]);
    }
    int ansSpace = max(solveSpaceOptimization(excludeFirst), solveSpaceOptimization(excludeLast));

    return ansSpace ;
}

int main(){

    return 0;
}