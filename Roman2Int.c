#include <stdio.h>

int roman2int(char *s);
char int2roman(int num);


int main(void)
{
    char s[] = "LCD";
    int number = 1994;
    printf("%d\n", roman2int(s));
    printf("%c\n", int2roman(number));
    return 0;
}


char int2roman(int num)
{
    return (char)num;
}


int roman2int(char* s)
{
    int result = 0;
    int current = 0;
    int next = 0;

    while (*s)
    {
        switch(*s)
        {
            case 'I': current = 1; break;
            case 'V': current = 5; break;
            case 'X': current = 10; break;
            case 'L': current = 50; break;
            case 'C': current = 100; break;
            case 'D': current = 500; break;
            case 'M': current = 1000; break;
        }

        switch(*(s + 1))
        {
            case 'I': next = 1; break;
            case 'V': next = 5; break;
            case 'X': next = 10; break;
            case 'L': next = 50; break;
            case 'C': next = 100; break;
            case 'D': next = 500; break;
            case 'M': next = 1000; break;
        }

        result += (current < next) ? -current : current; 
        s++;
    }

    return result;
}