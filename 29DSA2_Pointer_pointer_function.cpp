// pointers functions

#include<iostream>
using namespace std;

void print(int *p){
    cout<<*p<<endl;
}

void update(int *p){
    //  p = p + 1;
    //  cout<<"inside"<< p << endl;

    *p = *p +  1;

}

int getSum(int arr[] , int n){

    cout<<"size: "<<sizeof(arr)<<endl;   // will print size of address of first value of the array rather than whole size of the array
                                        // we pass the parameter int arr[] as int *arr
    int Sum = 0;                         // arr[i] = *(arr+i)
    for ( int i = 0; i<n; i++){ 
        Sum += arr[i];
    } 
    return Sum;
}

int getSum1(int arr[] , int n){

    cout<<"size: "<<sizeof(arr)<<endl;   // will print size of address of first value of the array rather than whole size of the array
                                        // we pass the parameter int arr[] as int *arr
    int Sum = 0;                         // arr[i] = *(arr+i)
    for ( int i = 0; i<n; i++){           // arr means address of first element in the array
        Sum += arr[i];                    // arr,&arr,&arr[0] are same
                                          // (arr+1) means address of element  present at  1th index
    } 
    return Sum;
}

int main(){ 

      int value =5;
      int *p = & value;

      //print(p);

      cout<<"Before "<< *p <<endl;
      update(p);
      cout<<"after "<< *p << endl;

      int arr[5] = {1,2,3,4,5};      //*(arr)= value of address at 0th element 

      cout<<"sum is "<< getSum(arr , 5)<<endl;
      cout <<" sum is "<< getSum1(arr+3,3);



    return 0;
}