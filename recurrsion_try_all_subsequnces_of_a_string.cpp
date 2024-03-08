#include<iostream>
using namespace std;

void subsequences(string str, int i, string newStr){
    if(i == str.length()){
        cout << newStr << " ";
        return ;
    }

    char currchar = str[i];

    // include the character 
    subsequences(str, i + 1, newStr + currchar);

    //exclude the charatcter 
    subsequences(str, i + 1, newStr);
}

int main(){
    string str = "abc";
    
    subsequences(str,0," ");
    return 0;
}