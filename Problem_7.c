#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10,001st prime number?
*/

bool is_prime(int num)
{
    if (num < 2) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0) return false;
    
    for (int i = 3; i <= sqrt(num); i += 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main(void)
{
    int count = 0;
    int num = 1;

    while (count < 10001)
    {
        num++;
        if (is_prime(num))
        {
            count++;
        }
    }

    printf("%d\n", num);
    return 0;
}
