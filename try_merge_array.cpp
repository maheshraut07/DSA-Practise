#include<iostream>
using namespace std;

void merge(int arr1[], int arr2[], int arr3[], int n , int m ){

    int i = 0;
    int j = 0;
    int k = 0;

    while(i < n && j < m){
        if(arr1[i] <= arr2[j]){
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else{
            arr3[k] = arr2[j];
            j++;
            k++;
        }
    }

    while(i < n){
        arr3[k] = arr1[i];
        i++;
        k++;

    }
    while(j < m){
        arr3[k] = arr2[j];
        j++;
        k++;
    }

    for(int i = 0; i < n+m; i++){
        cout<< arr3[i] << " ";
    }
}

int main(){
    int arr1[5] = {1,4,3,3,2};
    int arr2[3] = {4,3,6};
    int arr3[8] = {0};
    merge(arr1, arr2, arr3, 5, 3);

    return 0;

}