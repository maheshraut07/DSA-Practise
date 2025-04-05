#include <iostream>
#include <vector>
using namespace std;

// ✅ Optimized function for row-wise sorted binary matrix
int rowWithMax1sSorted(const vector<vector<int>> &arr) {
    int n = arr.size();
    int m = arr[0].size();
    int maxRow = -1;
    int j = m - 1;

    for (int i = 0; i < n; i++) {
        while (j >= 0 && arr[i][j] == 1) {
            j--;
            maxRow = i;
        }
    }
    return maxRow;
}

// ✅ Brute-force function for unsorted binary matrix
int rowWithMax1sUnsorted(const vector<vector<int>> &arr) {
    int maxCount = 0;
    int maxRow = -1;

    for (int i = 0; i < arr.size(); i++) {
        int count = 0;
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] == 1)
                count++;
        }

        if (count > maxCount) {
            maxCount = count;
            maxRow = i;
        }
    }

    return (maxCount == 0) ? -1 : maxRow;
}

// 🧪 Test sample in main
int main() {
    // ✅ Sample sorted binary matrix (each row is sorted)
    vector<vector<int>> sortedArr = {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };

    // ✅ Sample unsorted binary matrix
    vector<vector<int>> unsortedArr = {
        {1, 0, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 0, 0},
        {0, 0, 0, 0}
    };

    cout << "Row with max 1s in sorted matrix: " << rowWithMax1sSorted(sortedArr) << endl;
    cout << "Row with max 1s in unsorted matrix: " << rowWithMax1sUnsorted(unsortedArr) << endl;

    return 0;
}
