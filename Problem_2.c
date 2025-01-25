#include <stdio.h>
#include <math.h>
#include <stdbool.h>


bool IsFibo(int N)
{
    double num1 = sqrt(5.0 * N * N + 4);
    double num2 = sqrt(5.0 * N * N - 4);

    return (num1 == (int)num1) || (num2 == (int)num2);
}


int IndexFibo(double Fn) {
    const double sqrt5 = sqrt(5.0);
    const double phi = (1 + sqrt5) / 2;
    const double logPhi = log(phi);

    return (log(Fn * sqrt5) / logPhi);
}


long long Fibo(int n) {
    const double sqrt5 = sqrt(5.0);
    const double phi = (1 + sqrt5) / 2;
    const double psi = (1 - sqrt5) / 2;

    return (long long)((pow(phi, n) - pow(psi, n)) / sqrt5 + 0.5);
}


int main(void)
{
    int fn = 4000000;
    while (true)
    {
        fn--;
        if (IsFibo(fn))
        {
            break;
        }
    }

    int n = IndexFibo(fn);
    long long Sum = 0;
    for (int i = 3; i <= n; i = i + 3)
    {
        Sum+=Fibo(i);
    }
    printf("%lld\n", Sum);
    return 0;
}