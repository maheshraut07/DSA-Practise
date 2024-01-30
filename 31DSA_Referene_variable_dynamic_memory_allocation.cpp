// referance variables and dynamic memory locations

#include<iostream>
using namespace std;


int main(){         // referance variable means same memory but having diffrent names 
    int i=5;

    int &j = i;          //value of i and j is same ie. 5
    cout<< i << endl;
    i++;
    cout<< i << endl;
    j++;
    cout<< i << endl;  
    cout<< j << endl;         


    return 0;
}