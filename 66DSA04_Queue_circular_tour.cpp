#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

class petrolPump{
        public:
        int *petrol;
        int *distance;

};

int tour(petrolPump p[], int n) {
    int deficit = 0;     // deficinecy of petrol
    int balance = 0;    // balance petrol 
    int start = 0;       // starting position 

    for (int i = 0; i < n; i++) {
        balance += p[i].petrol - p[i].distance;  // find out the balance petrol by subtracting distance from the addition of balance petrol and and current petrol

        if (balance < 0) {                    // if balance is minus then add that balance into deficiency and start from the next index and set the balance equal to 0
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }

    if (deficit + balance >= 0) return start;
    else return -1;
}

// gfg 

// we have to give only the answer that traversal is possible or not 
// if possible return 1 otherwiese return -1
