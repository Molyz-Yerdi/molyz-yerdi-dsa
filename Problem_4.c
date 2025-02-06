#include <stdio.h>

/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 * 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*/

// Function to check if a number is a palindrome
int IsPalindrome(int num)
{
    int reversed = 0, original = num, remainder;
    
    while (num > 0)
    {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }
    
    return original == reversed;
}

int main(void)
{
    int max_palindrome = 0;
    int num1, num2;
    
    for (int i = 999; i >= 100; i--)
    {
        for (int j = i; j >= 100; j--)
        {
            int product = i * j;
            if (product <= max_palindrome) break;
            if (IsPalindrome(product))
            {
                max_palindrome = product;
                num1 = i;
                num2 = j;
            }
        }
    }
    
    printf("%d\n", max_palindrome);
    return 0;
}
