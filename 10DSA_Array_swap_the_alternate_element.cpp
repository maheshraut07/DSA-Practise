//Swap the alternate element in the array

#include<iostream>
using namespace std;

void printArray(int arr[], int n  ){
    for(int i = 0; i < n ; i++){
        cout << arr[i] << " ";

    }
    cout << endl;
}

void swapAlt(int arr[], int size){
    for(int i = 0; i < size; i+=2){
        if(i + 1 < size){
            swap(arr[i], arr[i+1]);
        }
    }
}
int main(){

    int arr[6]={1,25,4,5,6,8};
    int brr[5]={1,5,8,7,4};

    int a = sizeof(arr)/sizeof(arr[0]);
    int b = sizeof(brr)/sizeof(brr[0]);
    swapAlt(arr,a);
    printArray(arr,a);

    swapAlt(brr, b);
    printArray(brr,b);
    return 0;
}