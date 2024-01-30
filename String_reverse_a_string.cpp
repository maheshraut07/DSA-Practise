#include<iostream>
#include<algorithm>
using namespace std;

void reverse(string &str, int i , int j){
    if(i>j) return;
    
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    
    reverse(str,i++,j--);
    cout<<str;

}

int main(){
    string str = "mahesh";
    reverse(str, 0, str.length()-1);
 

    return 0;
}