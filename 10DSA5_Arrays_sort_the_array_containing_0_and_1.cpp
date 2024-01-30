// sort the aray containing only 1 and 0

#include <iostream>
#include <vector>
using namespace std;

void Sort(vector<int> &arr, int n)
{
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        while (arr[i] == 0 && i < j)
        {
            i++;
        }
        while (arr[j] == 1 && i < j)
        {
            j--;
        }
        if (arr[i] == 1 && arr[j] == 0 && i < j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    for (auto &p : arr)
    {
        cout << p << " ";
    }
}

int main()
{
    vector<int> arr;
    int n, a;
    cout << "Enter the size of the vector:";
    cin >> n;

    cout<<"enter the element in the vector: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }

    Sort(arr, n);

    return 0;
}