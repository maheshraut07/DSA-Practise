//check given array is sorted or not by using recurrsion

#include<iostream>
using namespace std;

bool isSorted(int arr[],int size){
    if(size == 0 || size == 1)
    return true;

    if(arr[0] > arr[1])
    return false;

    else {
         bool remainingPart = isSorted(arr +1 , size -1 );
         return remainingPart;
    }
  

}

int main(){

    int arr[6] = { 1,2,4,6,8,9};
    int size;

    bool ans = isSorted(arr,size);

    if(ans){
        cout<<"Array is sorted ";

    }
    else cout<<"Array is not sorted";

    return 0;
}