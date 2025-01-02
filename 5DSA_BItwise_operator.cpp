//Bitwise Operators

#include<iostream>
using namespace std;

int main(){
    int a = 4;
    int b = 6;

    cout <<"a&b : "<<(a&b)<< endl; // a=> 4 = 100, b=> 6 = 110 , a&b = 100 (6)
    cout <<"a|b : "<<(a|b)<< endl;
    cout <<"~a : "<< ~a << endl;
    cout <<"a^b : "<<(a^b)<< endl;

    cout<<(17>>1)<<endl; // 8
    cout<<(17>>2)<<endl; // 4
    cout<<(19<<1)<<endl; // 38
    cout<<(17<<2)<<endl; // 68

    int i = 5; 
    cout<<(i++)<<endl; //5 , i = 6
    cout<<(++i)<<endl; //7 , i = 7
    cout<<(i--)<<endl; // 7 , i = 6
    cout<<(--i)<<endl; // 5, i = 5
    return 0;
}