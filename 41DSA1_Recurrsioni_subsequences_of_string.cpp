#include <iostream>
#include <vector>
using namespace std;

void solve(string str, string output, int index, vector<string> &ans) {
    if (index >= str.length()) { // Base case
        ans.push_back(output);
        return;
    }

    // Exclude the current character
    solve(str, output, index + 1, ans);

    // Include the current character
    output.push_back(str[index]);
    solve(str, output, index + 1, ans);
}

vector<string> subsequences(string str) {
    vector<string> ans;
    string output = "";  // Fixed: removed space
    int index = 0;

    solve(str, output, index, ans);
    return ans;
}

int main() {
    string v = "mahesh";  // Fixed: Directly using a string

    vector<string> ans = subsequences(v);

    cout << "Subsequences of '" << v << "':\n";
    for (const string &s : ans) {
        cout << "\"" << s << "\"" << endl;
    }

    return 0;
}
