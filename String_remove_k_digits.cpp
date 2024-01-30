/*

Given a non-negative integer S represented as a string, remove K digits from the number so that the new number is the smallest possible.
Note : The given num does not contain any leading zero.

Example 1:

Input:
S = "149811", K = 3
Output: 
111
Explanation: 
Remove the three digits 
4, 9, and 8 to form the new number 111
which is smallest.
Example 2:

Input:
S = "1002991", K = 3
Output: 
21
Explanation: 
Remove the three digits 1(leading
one), 9, and 9 to form the new number 21(Note
that the output must not contain leading
zeroes) which is the smallest.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

string removeKdigits(string S, int K) {
    stack<char> st;

    for (char digit : S) {
        while (!st.empty() && K > 0 && st.top() > digit) {
            st.pop();
            K--;
        }

        if (!st.empty() || digit != '0') {
            st.push(digit);
        }
    }

    while (!st.empty() && K > 0) {
        st.pop();
        K--;
    }

    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());

    if (result == "") {
        result = "0";
    }

    return result;
        
        
    }