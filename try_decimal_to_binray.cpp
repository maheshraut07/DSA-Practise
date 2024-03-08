#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cout <<"ente any decimal number : ";
    cin >> n;

    string ans = "";

    while(n > 0){
        
        if(n%2 == 0) ans+='0';
        else ans+='1';
        
        n = n/2;
    }
    reverse(ans.begin(),ans.end());
    int Ans = stoi(ans);

    cout << "the equivalent binary number is : " << Ans; 
    return 0;
}