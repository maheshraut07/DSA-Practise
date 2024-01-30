//check palindrome using recurrsion

#include<iostream>
using namespace std;

bool checkPalindrome(string &str, int i , int j){
    if(i>j)
    return true;

    if(str[i]!=str[j])
    return false ;

    else 
    

        return checkPalindrome(str, i++,j--);

}

int main(){

    string name = "abba";
    cout<<endl;


    bool ispalindrome = checkPalindrome( name , 0 , name.length()-1);

    if(ispalindrome)
    cout<<" its a palindrome"<< endl;

    else cout<<"its not a palindrome"<< endl; 



    return 0;
}