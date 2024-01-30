// double pointers

#include<iostream>
using namespace std;

void update(int **p2 ){
    p2  = p2+1 ;
    *p2 = *p2+1;
    **p2 = **p2+1;

}

int main(){
    int i = 5; 
    int * p = & i;
    int ** p2 = & p;
    
    cout<<" \nprinting the address of i : "<< endl; //address
    cout<< p << endl;
    cout<< *p2 << endl;

    cout<<" \nprinting the value of i : " << endl;
    cout<< i << endl;
    cout<< * p << endl; 
    cout<< **p2 << endl;

    cout<<" \nprinting the value of p : "<< endl;
    cout<< &i << endl;
    cout<< p << endl;
    cout<< *p2 << endl;

    cout<<" \nprinting the value of p2: "<< endl;
    cout<< &p << endl;
    cout<< p2 << endl;


    cout<<"\nbefore "<< i << endl; 
    cout<<"before "<< p << endl; 
    cout<<"before "<< p2 << endl; 
    update(p2);
     cout<<"\nafter "<< i << endl; 
    cout<<"after "<< p << endl; 
    cout<<"after "<< p2 << endl; 
    cout<< endl;



    return 0;
}