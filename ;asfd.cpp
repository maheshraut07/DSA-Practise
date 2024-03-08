#include <bits/stdc++.h>
using namespace std;

// Utility function to rotate string S by one character to the left
string rotateLeftByOne(string S) {
    return S.substr(1) + S[0];
}

// Function to count occurrences of T in S after N rotations
int countOccurrences(int N, int M, string S, string T) {
    long long ans = 0;
    const long long MOD = 1e7;

    for (int rotation = 0; rotation < N; ++rotation) {
        // Check all substrings of S for a match with T
        for (int i = 0; i <= N - M; ++i) {
            bool match = true;
            for (int j = 0; j < M; ++j) {
                if (S[(i + j) % N] != T[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                ans = (ans + i + 1) % MOD; // Add 1 to convert 0-based to 1-based index
            }
        }
        S = rotateLeftByOne(S); // Rotate S to simulate magic button press
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    string S, T;

    cin >> N >> M;
    cin >> S >> T;

    int result = countOccurrences(N, M, S, T);

    cout << result << endl;

    return 0;
}
