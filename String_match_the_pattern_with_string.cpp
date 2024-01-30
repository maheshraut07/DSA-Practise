#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}


 vector <int> search(string pat, string txt)
        {
            //code hee.
            vector<int>v;
            int n = txt.length();
            int m = pat.length();
            
            for(int i = 0; i<n; i++){
                if(pat[0]==txt[i]){   // if first character of pat matches with text string then check for all the characters inside the text whether it is matching with pat or not 
                    string temp = txt.substr(i,m);
                    if(temp == pat){
                        v.push_back(i+1);
                    }
                }
            }
            if(v.empty()) 
                v.push_back(-1);
            
            return v;
        }


/*
Given two strings, one is a text string, txt and other is a pattern string, pat. The task is to print the indexes of all the occurences of pattern string in the text string. Use one-based indexing while returing the indices. 
Note: Return an empty list incase of no occurences of pattern. Driver will print -1 in this case.

Example 1:

Input:
txt = "geeksforgeeks"
pat = "geek"
Output: 
1 9
Explanation: 
The string "geek" occurs twice in txt, one starts are index 1 and the other at index 9. 
Example 2:

Input: 
txt = "abesdu"
pat = "edu"
Output: 
-1
Explanation: 
There's not substring "edu" present in txt.

*/