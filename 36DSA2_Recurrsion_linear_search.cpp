// linear search using recurrsion

#include<iostream>
using namespace std;

void print(int *arr, int n ){
    cout<<"the size of the array is : "<< n << endl;
    
    for( int i =0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<< endl ;
}

bool linearSearch(int *arr, int size , int k)
{   
    print(arr,size);
    if(size == 0){
        return false;
    }

    if(arr[0] == k){
        return true;
    }
    else{
        bool remainingPart = linearSearch(arr+1,size-1,k);
        return  remainingPart;
    }

}

int main(){

    int arr[5]= { 1,2,3,4,5};
    int size = 5;
    int key = 2;

    if(linearSearch(arr, size , key))
    cout<<"element found";
    else cout<<"element not found";
    
}