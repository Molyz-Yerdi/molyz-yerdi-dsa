#include <stdio.h>


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