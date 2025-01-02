#include <iostream>
#include <cmath>
using namespace std;

bool isPrimeBasic(int n)
{
    if (n <= 1)
        return false; // 0 and 1 are not prime numbers
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false; // Found a divisor
    }
    return true; // No divisors found
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (isPrimeBasic(num))
        cout << num << " is a prime number." << endl;
    else
        cout << num << " is not a prime number." << endl;
    return 0;
}

/*
The logic of running the loop until sqrt(n) (the square root of n) when checking for prime numbers is based on the mathematical property of divisors. Here's a detailed explanation of why this works:

Key Insight:
A prime number is a number greater than 1 that has no divisors other than 1 and itself. To check if a number n is prime, we need to see if any number divides n evenly (without a remainder). If we find such a divisor (other than 1 and n), then n is not prime.

Why Check Divisors Up to sqrt(n)?
Let’s consider the factors of n. If n can be factored into two numbers, say a and b, such that:

𝑛 = 𝑎 × 𝑏
n = a×b
If both a and b are greater than sqrt(n), then their product would be greater than n, which is a contradiction. This means that at least one of the two factors must be less than or equal to sqrt(n).

For example, consider n = 36:

36 = 6×6 = 4×9 = 2×18
36 = 6×6 = 4×9 = 2×18
Here, the factors are 2, 4, 6, 9, 18. Notice that the smaller factor in each case (2, 4, 6) is less than or equal to sqrt(36) (which is 6), and the larger factor (18, 9, 6) is greater than or equal to sqrt(36).

Thus, if n is divisible by any number a greater than sqrt(n), there must also be a corresponding divisor b smaller than sqrt(n). Therefore, it is sufficient to check for divisors only up to sqrt(n).





*/