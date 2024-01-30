/*
syntax 

return_type operator operator_type (){

}  

+ => a + b;  (a = this.a => current object , b = input)

*/

#include<iostream>
using namespace std;

class B{
    public:
    int a ;
    void operator + (B &obj){
        int value1 = this -> a;
        int value2 = obj.a;

        cout<<"Output: "<< value2 - value1;

    }
};


int main(){

B obj1;
B obj2;

obj1.a = 10;
obj2.a = 20;

obj1 + obj2;
    return 0;
}