#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MOD = 10000007;

int count(int n, int m, string s, string t) {
    int answer = 0;
    vector<int> prefix(m);
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && t[i] != t[j]) {
            j = prefix[j - 1];
        }
        if (t[i] == t[j]) {
            j++;
        }
        prefix[i] = j;
    }
    
    for (int k = 0; k < n; k++) {
        j = 0;
        string modifiedS = s.substr(k) + s.substr(0, k);
        for (int i = 0; i < n; i++) {
            while (j > 0 && modifiedS[i] != t[j]) {
                j = prefix[j - 1];
            }
            if (modifiedS[i] == t[j]) {
                j++;
            }
            if (j == m) {
                answer = (answer + (i - m + 2)) % MOD;
                j = prefix[j - 1];
            }
        }
    }
    
    return answer;
}

int main() {
    string s = "czab";
    string t = "abc";
    int n = s.length();
    int m = t.length();
    int result = count(n, m, s, t);
    cout << "Result: " << result << endl;
    return 0;
}