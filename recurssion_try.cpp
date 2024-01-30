#include<iostream>
using namespace std;

void get(int n){
    if(n < 1) return ;
    get(n-1);
    cout<<n<<" ";
    get(n-3);
    cout<<n<<" ";

}

int main(){
    get(6);
    return 0;

}