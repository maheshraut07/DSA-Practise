#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool ispar(string x) {
        stack<char> s;

        for (int i = 0; i < x.length(); i++) {
            char ch = x[i];

            if (ch == '(' || ch == '[' || ch == '{') {
                s.push(ch);
            } else {
                if (!s.empty()) {
                    char TOP = s.top();

                    if (ch == ')' && TOP == '(' ||
                        ch == ']' && TOP == '[' ||
                        ch == '}' && TOP == '}') {
                        s.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }

        // Check if the stack is empty after processing the entire string
        return s.empty();
    }
};

int main() {
    Solution S;

    string x = "(a+b]";
    if (S.ispar(x)) {
        cout << "String is well parenthesis" << endl;
    } else {
        cout << "String is not well parenthesis" << endl;
    }

    return 0;
}
