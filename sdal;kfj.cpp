#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int countIt(int N, int M, string S, string T) {
    const int MOD = 10000000;
    unordered_set<int> indices;

    for (int i = 0; i < N; i++) {
        string rotatedS = S.substr(N - i - 1) + S.substr(0, N - i - 1);
        for (int j = 0; j <= N - M; j++) {
            if (rotatedS.substr(j, M) == T) {
                indices.insert(j);
            }
        }
    }

    int ans = 0;
    for (int index : indices) {
        ans = (ans + index) % MOD;
    }

    return ans;
}

int main() {
    int N, M;
    string S, T;
    cin >> N >> M >> S >> T;

    int result = countIt(N, M, S, T);

    cout << result << endl;

    return 0;
}
