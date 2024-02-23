#include<iostream>
using namespace std;

void  reverseStr(string str, int n , string &ans ){

    if(n == 0){
        ans.push_back(str[n]);
        return ;
    }

    ans.push_back(str[n]);
    cout << "stepwise reverse string is : " << ans  << endl;
    reverseStr(str,n-1,ans);
}

int main(){
    string str = "mahesh";
    int n = str.length() - 1;
    string ans = " ";
    reverseStr(str,n, ans );

    cout << "the reverse of str is : " << ans ;
    return 0;
}