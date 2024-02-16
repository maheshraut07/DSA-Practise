#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<pair<int, int>> vec = {{1, 5}, {2, 3}, {3, 1}, {4, 4}, {5, 2}};

    sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    for (const auto& p : vec) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }

    return 0;
}


/*

another method for it 




#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comparator(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    vector<pair<int, int>> vec = {{1, 5}, {2, 3}, {3, 1}, {4, 4}, {5, 2}};

    sort(vec.begin(), vec.end(), comparator);

    for (const auto& p : vec) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }

    return 0;
}



*/
