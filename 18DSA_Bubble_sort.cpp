#include <bits/stdc++.h> 
#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>& arr, int n)
{   
    // Write your code here.
    for(int i = 1; i < n ; i++){
        for(int j = 0; j <n -i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
int main(){
    return 0;
}
