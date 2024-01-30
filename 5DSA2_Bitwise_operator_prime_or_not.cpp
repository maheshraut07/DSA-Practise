// program to check a given number is prime or not 

#include<iostream>
using namespace std;

int main(){
    int n ;
    cout<<"Enter any number n : ";
    cin>>n;

    bool isPrime = 1;
    for( int i = 2; i < 7; i++){
        if(n % i == 0){
            isPrime = 0;
            break;
        }
    }

    if(isPrime) cout<<"is a prime number "<<endl;
    else cout<<"Not a Prime Number"<<endl;
    return 0;
}
