//char pointers
#include<iostream>
using namespace std;

int main(){

    int arr[5] = { 1,2,3,4,5};
    char ch[6] ={'a','b','c','d','e'};

    cout<<ch<<endl;   // print entire string unlike array

    char *c = & ch[0];

    cout<<c<<endl;    // print entire string unlike array
    cout<<arr<<endl;  // print the address of the first element of the array
    cout<<&arr[0]<<endl;// print the address of the first element of the array
    cout<<&arr<<endl;// print the address of the first element of the array

    return 0;
}