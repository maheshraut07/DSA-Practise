// sum of array by using recurrsion

#include<iostream>
using namespace std;

int getSum(int *arr,int size){
    if(size == 0)
    return 0;

    if(size == 1 )
    return arr[0];

   
    int Sum = arr[0] + getSum(arr+1,size-1);
    return Sum;
}

int main(){
    int arr[5]= { 1,2,3,4,5};
    int size = 5;

    int ans = getSum(arr,size);

    cout<<"the sum of array is : "<< ans <<endl;

}