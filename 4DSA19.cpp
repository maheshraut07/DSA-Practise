/*

*****
 ****
  ***
   **
    *

*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int row = 1;
    while (row <= n)
    {
        int space = row - 1;
        while (space)
        {
            cout << " ";
            space--;
        }
        
        int col = 1;
        while (n-col-1)
        {
            cout << "*";
            col++;
        }
        
         cout << endl;
        row++;
    }
    return 0;
}