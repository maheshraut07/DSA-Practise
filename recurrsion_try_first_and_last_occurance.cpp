#include<iostream>
using namespace std;

pair<int,int> FirstAndLastOccu(string str, int n, int first ,int  last , int i , char target ){

    if (i == n ){
        pair<int,int> p = {first,last};
        return p;
    }

   if(str[i] == target){
    if(first == -1){
        first = i;
    }
    else last = i;
   }

   return  FirstAndLastOccu(str, n, first, last, i = i + 1, target);

}

int main(){

    string  str = "mahesh";
    int first = -1;
    int last = -1;
    int n = str.length();
    int i = 0;
    char target = 'h';

    pair <int,int> p  = FirstAndLastOccu(str, n, first, last , i, target );

    cout << "the first occurance of the " << target << " is : " << p.first << " and last occurance of the " << target << " is : " << p.second;
    
    return 0;
}
