#include<iostream>
using namespace std;

// void get(int n ){
//     n = n+1;
//     cout<<"\ninside get function n :"<<n;
// }
// int main(){
//     int n = 5;
//     get(n);
//     cout<<"\ninside main function n: "<<n;
//     return 0;
// }


void get(int &n ){
    n = n+1;
    cout<<"\ninside get function n :"<<n;
}
int main(){
    int n = 5;
    get(n);
    cout<<"\ninside main function n: "<<n;
    return 0;
}

