#include <stdio.h>

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.</p>
*/

int Number(int a)
{
    return (1000 - 1) / a;
}

int SumN(int a)
{
    int n = Number(a);
    int S = (2 * a + a * (n - 1)) * n / 2;

    return S;
}

int main(void)
{
    int Sum = SumN(3) + SumN(5) - SumN(15);
    printf("%d\n", Sum);

    return 0;
}