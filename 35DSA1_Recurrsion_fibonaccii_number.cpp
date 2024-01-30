//fibonacci number by recurssion

#include<iostream>
using namespace std;

int fib(int n){

    if(n==0)
    return 0;

    if(n==1)
    return 1;

    int ans = fib(n-1) + fib(n-2);
    return ans;
}

int main(){

    int n;
    cout<<"Enter the value of total number of terms: ";
    cin>>n;

    cout<<endl;
    cout<<"fibonaccin series is: "<<fib(n);

  
    return 0;

}

//time complexity 0(2**n)
//space complexity = 0(n)