#include <iostream>
#include <string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

const int MOD = 10000007;

int countOptimized(int n, int m, string s, string t) {
    // Concatenate s with itself to simulate all rotations
    string concatenatedS = s + s;
    int answer = 0;
    
    // Preprocess the pattern t to generate lps array
    vector<int> lps(m, 0);
    for (int i = 1, len = 0; i < m;) {
        if (t[i] == t[len]) {
            lps[i++] = ++len;
        } else if (len) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    
    // Perform KMP search on concatenatedS with pattern t
    for (int i = 0, j = 0; i < 2 * n;) {
        if (concatenatedS[i] == t[j]) {
            i++, j++;
            if (j == m) {
                // Check if the starting index of the found pattern is within the first n characters of concatenatedS
                if (i - j < n) {
                    answer = (answer + (i - j + 1)) % MOD;
                }
                j = lps[j - 1];
            }
        } else if (j) {
            j = lps[j - 1];
        } else {
            i++;
        }
    }
    
    return answer;
}

int main() {
    string s = "czab";
    string t = "abc";
    int n = s.length();
    int m = t.length();
    int result = countOptimized(n, m, s, t);
    cout << "Result: " << result << endl;
    return 0;
}
