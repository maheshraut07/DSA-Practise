#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; 
    cout << "enter any binary number : ";
    cin >> n;

    int i = 0;
    int ans = 0;
    

    while(n > 0){
        int bit = n % 10;
        
        ans += bit * pow(2,i);

        n /= 10;

        i++;

    }

    cout << "its equivalent decimal number is : " << ans ;

    return 0;
}