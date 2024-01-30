#include<iostream>
using namespace std;

int main(){

    int a = 0;
    int b = 1;

    int n = 8;

    cout << a << " " << b << " " ;

    for(int i = 0 ; i < n ; i++){
        int nextNumber = a + b;
        cout << nextNumber << " ";

        a = b; 
        b = nextNumber;
    }


    
    return 0;
}