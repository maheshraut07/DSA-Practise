//get length of given array end reverse array 
#include<iostream>
using namespace std;
int getlength(char name[]){
    int count = 0;
    for ( int i = 0; name[i] !='\0'; i++){
        count++;
    }
}

 void reverse(char name[] , int n){
    int s =0; 
    int e = n-1;

    while(s<e){
        swap(name[s++],name[e--]);
    }
}

int main(){
    char name[20];
    cout<<"enter your name:"<<endl;
    cin>>name;
    cout<<"your name is:";
    cout<<name<<endl;

    cout<<"the length of name is:"<<getlength<<endl;

    return 0;
}

