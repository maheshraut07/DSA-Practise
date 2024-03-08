#include<iostream>
using namespace std;

void merge(int *arr, int s, int e) {
    int mid = (s + e) / 2;
    int n = mid - s + 1;
    int m = e - mid;

    int *a = new int[n];
    int *b = new int[m];

    // Copy values into a array from the original array till mid element;
    int mainArrayIndex = s;
    for (int i = 0; i < n; i++) {
        a[i] = arr[mainArrayIndex];
        mainArrayIndex++;
    }
    
    // copy values into b array from the original array  till last element from the mid element 
    mainArrayIndex = mid + 1;
    for (int i = 0; i < m; i++) {
        b[i] = arr[mainArrayIndex];
        mainArrayIndex++;
    }

    // Merge two sorted arrays
    int i = 0;
    int j = 0;
    mainArrayIndex = s;

    while (i < n && j < m) {
        if (a[i] < b[j]) {
            arr[mainArrayIndex] = a[i];
            mainArrayIndex++;
            i++;
        } else {
            arr[mainArrayIndex] = b[j];
            mainArrayIndex++;
            j++;
        }
    }

    while (i < n) {
        arr[mainArrayIndex] = a[i];
        mainArrayIndex++;
        i++;
    }

    while (j < m) {
        arr[mainArrayIndex] = b[j];
        mainArrayIndex++;
        j++;
    }

    delete[] a;
    delete[] b;
}

void mergesort(int *arr, int s, int e) {
    if (s >= e)
        return;

    int mid = (s + e) / 2;

    mergesort(arr, s, mid);    // Left part sorted
    mergesort(arr, mid + 1, e); // Right part sorted
    merge(arr, s, e);           // Merge two arrays
}

int main() {
    int arr[5] = {2, 5, 1, 6, 9};
    int n = 5;

    mergesort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
