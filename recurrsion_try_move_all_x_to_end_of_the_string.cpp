#include<iostream>
using namespace std;

void moveAllX (string str, int n , int i , string &newStr, int cnt, char target  ){

    if( i == n){
        if(str[i] == target) cnt ++;
        else newStr.push_back(str[i]);
        while(cnt--) newStr.push_back(target);
        return ;
    }
    if(str[i] == target ) cnt++;
    else newStr.push_back(str[i]);
    
    return moveAllX(str, n, i = i + 1, newStr, cnt , target);

    
}

int main(){
    string str = "mahwweklsaskadfwwwerw";
    char target = 'w';
    int i = 0;
    string newStr = "";
    int n = str.length();
    int cnt = 0;
    moveAllX(str, n, i, newStr , cnt, target ) ;

    cout << "the new string is : " << newStr;
    return 0;
}