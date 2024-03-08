#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "enter value of n :";
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        cout << "enter the value : ";
            cin >> i;
    }

            cout <<"\n given values are : ";

    for (int i = 1; i <=n; i++)
    {
        cout<<i<<" ";
    }

    return 0;
}