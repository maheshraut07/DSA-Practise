#include<iostream>
using namespace std;

int power(int n){
    if(n==0) 
    return 1;

    int pow = 2* power(n-1);
    return pow;
}

void print(int n){
    if(n==0) 
    return ;

    cout<< n << endl;
    print(n-1);              //print = 5 4 3 2 1 
}

void print1(int n){
    if(n==0) 
    return ;

    print1(n-1);
    cout<< n << endl;        // print = 1 2 3 4 5 
}

int main(){

    int n;
    cout<<"Enter the value for finding the 2th power: ";
    cin>>n;

    cout<<"the "<<n<<"th power of 2 is : "<<power(n)<<endl;
    cout<< endl ;
    print(n);
    cout<<endl<<endl;
    print1(n);




    return 0;
}