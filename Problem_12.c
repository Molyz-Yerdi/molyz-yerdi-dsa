#include <stdio.h>
#include <math.h>

int count_divisors(int num)
{
    int count = 0;
    int sqrt_n = (int)sqrt(num);

    for (int i = 1; i <= sqrt_n; i++)
    {
        if (num % i == 0)
        {
            count += 2;
            if (i * i == num)
            {
                count--;
            }
        }
    }
    return count;
}

int find_triangle_number()
{
    int n = 1;
    int triangle = 1;

    while (count_divisors(triangle) <= 500)
    {
        n++;
        triangle += n;
    }

    return triangle;
}

int main()
{
    int result = find_triangle_number();
    printf("%d\n", result);
    return 0;
}
