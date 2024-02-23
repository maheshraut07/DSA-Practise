#include<iostream>
using namespace std;

void calcFibo(int a , int b , int n  ){ 
    if(n == 0){
        cout << endl;
        return ;

    }
    int c = a + b;

    cout << c << " ";
    calcFibo(b, c, n = n-1);
    cout << c << " ";



}

int main(){
    int a = 0;
    int b = 1;

    int n  = 10;
    

    calcFibo(a,b,n-2);

    return 0;
}