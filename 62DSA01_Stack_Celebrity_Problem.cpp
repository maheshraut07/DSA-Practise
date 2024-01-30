#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    bool knows(vector<vector<int>> &M, int a, int b, int n){
        
        if (M[a][b] == 1) return true;
        else return false;
    }


    int celebrity(vector<vector<int>> &M, int n){
        // code here
        stack<int> s;
        for (int i = 0; i < n; i++)
        { // push all the elements in the stack
            s.push(i);
        }

        // step 2 = get 2 elements and compare them

        while (s.size() > 1)
        {
            int a = s.top();
            s.pop();
            int b = s.top();

            if (knows(M, a, b, n))
            {
                s.push(b);
            }
            else
            {
                s.push(a);
            }

            int ans = s.top();

            // step 3 : single element in stack in potential candidate to be a celebrity , so verify it
            //  rowcheck

            bool rowcheck = false;
            int zerocount = 0;

            for (int i = 0; i < n; i++)
            {
                if (M[ans][i] == 0)
                {
                    zerocount++;
                }
            }
            // if all are zeros then rowcount = true;
            if (zerocount == n)
            {
                rowcheck = true;
            }

            // columncheck;

            bool columncheck = false;
            int onecount = 0;

            for (int i = 0; i < n; i++)
            {
                if (M[i][ans] == 1)
                {
                    onecount++;
                }
            }

            if (onecount == n - 1)
            {
                columncheck = true;
            }

            if (rowcheck == true && columncheck == true)
            {
                return ans;
            }
            else
            {
                return -1;
            }
        }
    }
};

int main()
{

    return 0;
}