#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIMIT 2000000

/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
*/

long sum_primes(int limit);


int main()
{
    printf("%ld\n", sum_primes(LIMIT));
    return 0;
}


long sum_primes(int limit)
{
    bool *is_prime = calloc(limit, sizeof(bool));
    long sum = 0;

    for (int i = 2; i < limit; i++)
    {
        is_prime[i] = true;
    }

    for (int i = 2; i < limit; i++)
    {
        if (is_prime[i])
        {
            sum += i;
            for (int j = 2 * i; j < limit; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    free(is_prime);
    return sum;
}