#include<bits/stdc++.h>
using namespace std;

int main (){
    return 0;
}
class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
       if (array1.size() > array2.size()) {
            swap(array1, array2);
        }

        int x = array1.size();
        int y = array2.size();

        int low = 0;
        int high = x;

        while (low <= high) {
            int i1 = (low + high) / 2;
            int i2 = (x + y + 1) / 2 - i1;

            int max1 = (i1 == 0) ? INT_MIN : array1[i1 - 1];
            int max2 = (i2 == 0) ? INT_MIN : array2[i2 - 1];

            int min1 = (i1 == x) ? INT_MAX : array1[i1];
            int min2 = (i2 == y) ? INT_MAX : array2[i2];

            if (max1 <= min2 && max2 <= min1) {
                if ((x + y) % 2 == 0) {
                    return (max(max1, max2) + min(min1, min2)) / 2.0;
                } else {
                    return max(max1, max2);
                }
            } 
            else if (max1 > min2) {
                high = i1 - 1;
            } 
            else {
                low = i1 + 1;
            }
        }
    
    }
};