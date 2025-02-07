#include <stdio.h>

/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

// Function to find the greatest common divisor (GCD)
int GCD(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find the least common multiple (LCM)
int LCM(int a, int b)
{
    return (a / GCD(a, b)) * b;
}

int main()
{
    int result = 1;

    for (int i = 2; i <= 20; i++) 
    {
        result = LCM(result, i);
    }

    printf("%d\n", result);
    return 0;
}
