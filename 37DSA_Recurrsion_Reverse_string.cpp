//reverse string using recurrsion

#include<iostream>
using namespace std;

void reverse( string &str, int i , int j){
    
    if(i>j)
    return ;

    
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
 
    reverse(str,i++,j--);
}

int main(){
    
    string name = "babbar";

    reverse( name , 0, name.length()-1);
    cout<< name << endl;

    
    return 0;
}
