//Decimal and binary systems
#include<iostream>
#include<math.h>
using namespace std;

int main(){

    int n;
    cout<<"Enter any decimal Number:  ";
    cin>>n;
    cout << endl;

    int ans = 0;
    int i = 0;
    while(n != 0){
        int bit = n & 1;
        cout << "the bit is : " << bit << endl;

        ans = (bit * pow(10,i)) + ans;
        cout << "the ans is : " << ans << endl;
        n = n >> 1;
        cout << "the value of n is : " <<  n << endl;
        i++;
        cout << "the value of i is : " << i << endl;
        cout << endl;
    }

    cout<<"Answer is : "<< ans;
   
}



/*
123

ans = 0
 ans = (ans * 10) + digit; = 1
 0*10+1 = 1;
 1*10+2 = 12;
 12*10+3 = 123
 
 for reversing it 
 
 ans = digit * 10^i + ans :
 1*10^0+0 = 1
 2*10^1+1 = 21
 3*10^0+3 = 321
 

 */






/*2nd approach

#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n ;
    cin >> n;
    
    int ans = 0;
    for(int i = 0; n != 0; i++){
        int bit = n & 1;
        ans += bit * pow(10,i);
        n >>= 1;
    }
    
    cout << ans;
    return 0;
}
*/