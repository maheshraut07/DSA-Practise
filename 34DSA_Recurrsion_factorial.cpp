/* Recurrsion :-
   when function call itself repeatedly directly or inddirectly is 
   called as recurssion

   when function reach at his last function call is called 
   as his base case or base condition

   we have to state two condtions
   1) base case (mendatory it state that at what position we have to stop )
   2) recurrsive relation
*/

#include<iostream>
using namespace std;

int factorial(int n){
    if(n==0 || n==1){
        return 1;
    }

    return (n*factorial(n-1));
    
}

int main(){

    
    int n;
    cout<<"Enter the value to find factorial: ";
    cin>>n;
     
    cout<<"factorial is : "<<factorial(n)<<endl;
    return 0;
}


//time complexity = 0(n)
//space complexity = 0(n)