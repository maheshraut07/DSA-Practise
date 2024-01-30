#include <stack>
#include<bits/stdc++.h>

class SortedStack {
public:
    std::stack<int> s;
    void sort();
};

using namespace std;

int main(){
    
    return 0;
}

void sortedInsert(std::stack<int>& s, int num);

void SortedStack::sort() {
    if (s.empty()) {
        return;
    }

    int num = s.top();
    s.pop();

    sort();
    sortedInsert(s, num);
}

void sortedInsert(std::stack<int>& s, int num) {
    if (s.empty() || (!s.empty() && s.top() < num)) {
        s.push(num);
        return;
    }

    int n = s.top();
    s.pop();

    sortedInsert(s, num);
    s.push(n);
}