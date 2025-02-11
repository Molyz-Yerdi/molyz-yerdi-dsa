#include <stdio.h>

/*
The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385.
The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 55^2 = 3025.
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

int main(void)
{
    int n = 100;
    long sum_of_squares = 0;
    long square_of_sum = 0;
    long difference;

    for (int i = 1; i <= n; i++)
    {
        sum_of_squares += i * i;
        square_of_sum += i;
    }

    square_of_sum = square_of_sum * square_of_sum;
    difference = square_of_sum - sum_of_squares;

    printf("%ld\n", difference);
    return 0;
}
