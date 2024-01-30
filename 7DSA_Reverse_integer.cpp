// Reverse Integer

#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"enter the number: ";
    cin>>n;

    int ans = 0;
    while( n != 0){
        int digit = n % 10;
        if(ans > INT32_MAX || ans < INT32_MIN){
            return 0;
        }
        ans = ans * 10 + digit;
        n = n / 10;
    }

    cout<<"the reverse integer is: "<<ans;
    return 0;
}