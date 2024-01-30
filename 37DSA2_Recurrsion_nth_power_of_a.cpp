//finding nth power of A using recurrsion

#include<iostream>
using namespace std;

int power( int a, int b){
    if( b==0) 
    return 1;

    if ( b==1)
    return a;

    int ans = power(a,b/2);
   
    
    if(b%2 ==0)
    return ans*ans;

    else 
    return a*ans*ans;
}

int main(){

    int a,b;
    cout<<"Enter the values of a and b: ";
    cin>> a >> b;
    cout<< endl ;

    int n = power(a,b);
    cout<<n;

    return 0;
}

 