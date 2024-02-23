#include<iostream>
using namespace std;

bool isSorted(int i , int n , int arr[]){

    //base case 

    if(i == n ) return true;

    if(arr[i] < arr[i-1]) return false;

    return isSorted(i = i + 1, n , arr);

}

int main(){
    int arr[] = { 1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i = 1;

    if( isSorted(i, n , arr)) cout << "array is sorted";
    else cout << "arrya is not sorted ";

    return 0;
}