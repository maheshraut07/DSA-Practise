#include<iostream>
#include<vector>
using namespace std;


void selectionSort(vector<int>& arr, int n)
{   
    // Write your code here.
    
    for(int i = 0 ; i< n-1; i++){
        int MININDEX = i;
        for(int j = i +1 ; j < n; j++){
            if(arr[j] < arr[MININDEX]){
                MININDEX = j;
            }
        }
        swap(arr[MININDEX] , arr[i]);
    }
    for(auto i : arr){
        cout<<i<<" ";
    }
}

int main(){
    vector<int> arr = {10,50,70,40,20};
    int n = arr.size();

    selectionSort(arr,n);
    return 0;
}