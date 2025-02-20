#include <stdio.h>

/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2.
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc.
*/

int main(void)
{
    int a, b, c;
    int sum = 1000;

    for (a = 1; a < sum / 3; a++)
    {
        for (b = a + 1; b < sum / 2; b++)
        {
            c = sum - a - b;
            if (a * a + b * b == c * c)
            {
                printf("%d\n", a * b * c);
                return 0;
            }
        }
    }
    return 1;
}
