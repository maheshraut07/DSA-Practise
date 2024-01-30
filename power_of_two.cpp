#include<iostream>
using namespace std;

int main(){
    int n ;
    cin>>n;
    if(n&(n-1)){
        cout<<"not the power of two";
    }
    else cout<<"powert of two";
    return 0;
}