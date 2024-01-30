#include<iostream>
#include<stack>
using namespace std;
class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack < char > s;
        for(int i = 0; i < x.length(); i++){
            char ch = x[i];
            
            if(ch == '{' || ch == '(' || ch == '['){
                s.push(ch);
            }
            else{
                if(!s.empty()){
                    char TOP = s.top();
                    
                    if(ch == '}' && TOP == '{' ||
                       ch == ')' && TOP == '(' ||
                       ch == ']' && TOP == '['){
                           s.pop();
                       }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        
        if(s.empty()){
            return true;
        }
        else{
            return false;
        }
    }

};

int main(){
    Solution S;
    string x = "(a+b)";
    if(S.ispar(x)) cout << " True";
    else cout << " false" ;
   
    
    return 0;
}