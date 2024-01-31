/*

You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}


class Solution {

    long resolves(int a, int b, char Operator){
        if(Operator == '+') return a + b;
        else if(Operator == '-') return a - b;
        else if(Operator == '*') return (long)a*b;
        return a/b;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> Stack;
        int n = tokens.size();
        for(int i = 0; i < n; i++){

            if(tokens[i].size() == 1 and tokens[i][0] < 48){  // it checks if the character is a non-digit character
                long integer2 = Stack.top();
                Stack.pop();
                long integer1 = Stack.top();
                Stack.pop();
                
                string Operator = tokens[i];
                long resolvedAns = resolves(integer1, integer2 , Operator[0]);
                Stack.push(resolvedAns);
            }else 
                Stack.push(stol(tokens[i]));
        }
        return Stack.top();
    }
};

