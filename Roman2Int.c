#include <stdio.h>
#include <string.h>

#define SIZE 50

int roman2int(char *s);
void int2roman(char *result, int number, size_t size);

const struct {
    const char *symbol;
    int value;
} roman_map[13] = {
    {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100},
    {"XC", 90},  {"L", 50},   {"XL", 40}, {"X", 10},   {"IX", 9},
    {"V", 5},    {"IV", 4},   {"I", 1}
};


int main(void)
{
    // char s[] = "LCD";
    // printf("%d\n", roman2int(s));

    char result[SIZE];
    int number = 1994;
    int2roman(result, number, SIZE);
    printf("%s\n", result);

    return 0;
}

void int2roman(char *result, int number, size_t size)
{
    const struct
    {
        const char *symbol;
        int value;
    }
    roman_map[13] = {{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100},
                     {"XC", 90},  {"L", 50},   {"XL", 40}, {"X", 10},   {"IX", 9},
                     {"V", 5},    {"IV", 4},   {"I", 1}};

    for (int i = 0; number > 0; ++i)
    {
        while (number >= roman_map[i].value)
        {
            number -= roman_map[i].value;
            strncat(result, roman_map[i].symbol, size);
        }
    }
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