//pivot element in the given array
#include<iostream>
using namespace std;

int getpivot(int arr[], int n ){
    int s = 0;
    int e = n-1;
    int mid = s + ( e-s )/2;

    while(s<=e){
        if ( arr[mid]>=arr[0]){
            s = mid +1 ;

        }
        else {
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int main (){
    int arr[5]= {3,9,10,11,1};
    cout<<"Pivot element is at index: "<<getpivot(arr,5)<<endl;

    return 0;
}

//pivot element is the element is the element which has the sum of all elements at left side equal to sum of all elements at right side