#include <stdio.h>
#include <stdlib.h>

// Function for fast modular exponentiation (a^b % mod)
long long ModPow(long long base, long long exp, long long mod)
{
    long long result = 1;
    base = base % mod;
    
    while (exp > 0) 
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// One round of the Miller-Rabin test
int MillerRabin(long long n, long long a)
{
    long long d = n - 1;
    int r = 0;

    while (d % 2 == 0)
    {
        d /= 2;
        r++;
    }

    long long x = ModPow(a, d, n);
    if (x == 1 || x == n - 1)
    {
        return 1;
    }

    for (int i = 0; i < r - 1; i++)
    {
        x = (x * x) % n;
        if (x == n - 1)
        {
            return 1;
        }
    }

    return 0;
}

// Function to check if a number is prime using the Miller-Rabin test
int IsPrime(long long n, int iterations)
{
    if (n < 2) { return 0; }
    if (n == 2 || n == 3) { return 1; }
    if (n % 2 == 0) { return 0; }

    int test_bases[5] = {2, 3, 5, 7, 11};
    for (int i = 0; i < iterations; i++)
    {
        long long a = test_bases[i % 5];
        if (a >= n) 
        {
            break;
        }
        if (!MillerRabin(n, a))
        {
            return 0;
        }
    }

    return 1;
}

// Finding the largest prime factor
long long PrimeFactor(long long N)
{
    long long largest_factor = 1;

    // Remove all factors of 2
    while (N % 2 == 0)
    {
        largest_factor = 2;
        N /= 2;
    }

    // Check odd divisors from 3 to sqrt(N)
    for (long long i = 3; i * i <= N; i += 2)
    {
        while (N % i == 0)
        {
            if (IsPrime(i, 5))  // Check if i is prime
            {
                largest_factor = i;
            }
            N /= i;
        }
    }

    // If there is any number left > 1, it is prime
    if (N > 1 && IsPrime(N, 5))
    {
        largest_factor = N;
    }

    return largest_factor;
}

// Main function
int main(void)
{
    long long N = 600851475143LL;
    long long largest_factor = PrimeFactor(N);
    printf("%lld\n", largest_factor);
    return 0;
}
