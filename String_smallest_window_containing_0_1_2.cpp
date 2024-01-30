#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

int smallestSubstring(string S) {
       
       int res = INT_MAX;
       bool zero = false, one = false, two = false;
       int zeroIn = -1, oneIn = -1, twoIn = -1;
       
       for(int i = 0; i < S.length(); i++){
           if(S[i] == '0'){
               zero = true;
               zeroIn = i;
           }
           else if(S[i] == '1'){
               one = true;
               oneIn = i;
           }
           else if(S[i] == '2'){
               two = true;
               twoIn = i;
           }
           
           if(zero && one && two){
             res = min(res, max({zeroIn, oneIn, twoIn}) - min({zeroIn, oneIn, twoIn}));
           }
       }
       
       if(res == INT_MAX) return -1;
       else return res+1;
    }

    /*
    Input:
S = 01212
Output:
3
Explanation:
The substring 012 is the smallest substring
that contains the characters 0, 1 and 2.
    */