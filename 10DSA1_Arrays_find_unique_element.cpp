/*find unique element in the array
ie. 1,2,3,3,4,2,1  unique element is 4
*/

int findUnique(int *arr, int size)
{
    //Write your code here
    int ans = 0;
    for(int i = 0; i < size; i++){
        ans = ans ^ arr[i];
    }
    return ans;
}