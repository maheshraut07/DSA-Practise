#include<bits/stdc++.h>
using namespace std;

vector<int> insertionSort(vector<int> &arr){

    int n = arr.size();

    for(int i = 1; i < n; i++){

        int key = arr[i];
        int j = i -1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j -1;
        }

        arr[j+1] = key;

    }

    return arr;
}

int main(){
    vector<int> arr = {12,11,13,5,6};
    vector<int> ans = insertionSort(arr);

    cout << "the sorted array is : ";
    for(int i : ans){
        cout << i << " ";
    }

    return 0;
}