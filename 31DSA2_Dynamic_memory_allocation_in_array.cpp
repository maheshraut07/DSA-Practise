/* 
dynamic memory allocation 

new int ;( here new word is used for creating new memory for int datatype in heap)
         but we cant give name to that int 
         it will return address of that particular location
         for accessing that particular location 
         we need to create pointer for that location 

         hence we create a pointer as follows

int  *c = new int;
char *a = new char ;



syntax for creating the array of memory location 

int *arr = new int[5];   (array of 5 elements  )

*/

#include<iostream>
using namespace std;

int getSum( int *arr,int n){
     int Sum = 0;
     for (int i =0; i<n; i++){
        Sum+=arr[i];
     }
}

int main(){

    int n;
    cin>>n;

    int *arr = new int[n];   // variable size array
    for ( int i=0; i<n; i++){  // taking input in array
        cin>> arr[i];
    }

    int ans = getSum(arr,n);
    cout<<"answer is : "<< ans << endl;

    return 0;
}

/*

int *arr= new int[n]

in above line of code arr is the pointer and it 
will store the address of the first element in the
int[n] in the heap memory which is created dynamically



int arr[50] (declaration  of array in static memory location )
int *arr = new int[50] (declaration of array in dynamic array location )
*/
