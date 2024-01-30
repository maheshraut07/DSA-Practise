// referance variables in functions 

#include<iostream>
using namespace std;

 void update(int n){
    n++;
}

void update2(int &j){
    j++;
}

int main(){

    int n = 5;
    cout<< " before "<< n << endl;
    update(n);
    cout<<" after "<< n << endl;  // value remains same

    update2(n);
    cout<<" after "<< n << endl;   // value will be updated


}

/*referance variable means for same memory locations there are different names
 eg. int i=5;
       int &j = i;

       here value of i and j will be same ie. 5
       
       
NOTE=       in call by value function call there is creation of new memory location 
       but in call by reference function call there is no creation of new memory location   */