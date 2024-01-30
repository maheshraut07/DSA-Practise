/*
A
BB
CCC
DDDD
EEEEE
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    int row = 1;
    while(row <= n){
        int col = 1;
        
        char ch = 'A';
        while(col <= row){
            char m  = ch+row-1;
            cout<<m;
            col++;
        }
        cout<<endl;
        row++;
    }
    return 0;
}