#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 15;
    string m = to_string(15);
    cout <<  "type of m is : " << typeid(m).name() << endl;
    int x = stoi(m);
    cout << "type of x is : " << typeid(x).name()  << endl;

    string name = "mahesh";
    cout << "type of mahesh is : " << typeid(name).name()  << endl;

    return 0;
}   