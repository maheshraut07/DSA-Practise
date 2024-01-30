#include<iostream>
using namespace std;

void heapify(int *arr, int n , int i ){

    int largest = i; 
    int leftIndex = 2 * i ;
    int rightIndex = 2 * i + 1;

    if(leftIndex <= n && arr[largest] < arr[leftIndex]){
        largest = leftIndex;
    }
    else if(rightIndex <= n && arr[largest] < arr[rightIndex]){
        largest = rightIndex;
    }  

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }

}

void heapsort(int *arr, int n){
    int size = n;

    while( size > 1){
        swap (arr[size], arr[1]);

        size--;

        heapify(arr, n , 1);
    }
}


int main(){

    int arr[6] = {-1, 10, 12, 14, 13, 15};
    int n = 5;

    for(int i = n/2; i > 0; i--){   // buildheap
        heapify(arr, n, i);
    }

    cout << "printing the array after heapsort :" << endl;
    heapsort(arr, n);
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}