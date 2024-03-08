#include <bits/stdc++.h>
using namespace std;

string trim(string);

int countIt(int N, int M, string S, string T) {
    long long ans = 0;
    long long p = 1;
    long long MOD = 1e7;

    for (int i = 0; i < M - 1; i++) {
        p = (p * 26) % MOD;
    }

    long long hashS = 0, hashT = 0;
    for (int i = 0; i < M; i++) {
        hashT = (hashT * 26 + (T[i] - 'a')) % MOD;
        hashS = (hashS * 26 + (S[i] - 'a')) % MOD;
    }

    if (hashS == hashT) ans++;

    for (int i = M; i < N; i++) {
        hashS = (((hashS - (S[i - M] - 'a') * p) % MOD + MOD) * 26 + (S[i] - 'a')) % MOD;
        if (hashS == hashT) ans++;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string inputline;
    getline(cin, inputline);
    int N = stoi(trim(inputline));

    getline(cin, inputline);
    int M = stoi(trim(inputline));

    // Reading the next line into string S
    getline(cin, inputline);
    string S = inputline;

    // Reading the next line into string T
    getline(cin, inputline);
    string T = inputline;

    int result = countIt(N, M, S, T);

    cout << result << endl;

    return 0;
}

string trim(string s) {
    size_t firstScan = s.find_first_not_of(' ');
    size_t first = (firstScan == string::npos) ? s.length() : firstScan;
    size_t last = s.find_last_not_of(' ');
    return s.substr(first, last - first + 1);
}
