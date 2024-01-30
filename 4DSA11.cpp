/*
ABCDE
ABCDE
ABCDE
ABCDE
ABCDE
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
            char m  = ch+col-1;
            cout<<m;
            col++;
        }
        cout<<endl;
        row++;
    }
    return 0;
}