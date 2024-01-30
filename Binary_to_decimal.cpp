#include<iostream>
#include<math.h>
using namespace std;

void BinaryToDecimal(int n){
    int i = 0;
    int ans = 0;
    while(n != 0){
        int digit = n % 10;
        if(digit == 1){
            ans = ans + pow(2,i);
        }

        n = n/10;
        i++;
    }
    cout<<"its equivalent decimal number is: "<<ans;

}
int main()
{   char ch;
    do{
        cout<<"Enter the any binary number to convert into decimal : ";
        int n;
        cin>>n;
        BinaryToDecimal(n);
        cout<<endl;
        cout<<endl;
        cout<<"Do you want to continue (y/n) : ";
        cin>>ch;
       
    }while( ch !='y' || ch !='n');
     return 0;
}

// code to convert binary to decimal