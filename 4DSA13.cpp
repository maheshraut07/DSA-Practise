/*
ABCDE
BCDEF
CDEFG
DEFGH
EFGHI

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
        while(col <= n){
            char m  = ch+row + col-2;
            cout<<m;
            col++;
        }
        cout<<endl;
        row++;
    }
    return 0;
}