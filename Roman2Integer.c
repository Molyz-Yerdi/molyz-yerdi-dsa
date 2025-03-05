#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_integer(const char* arg, int* ptr_num);
void integer_to_roman(char* ptr_str, int* ptr_num);
int roman_to_integer(char *str);

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("ERROR: NO ARGUMENT PROVIDED\n");
        return 0;
    }

    int number = 0;
    char *string = (char*)calloc(256, sizeof(char));

    if (is_integer(argv[1], &number))
    {
        integer_to_roman(string, &number);
        printf("%s\n", string);
        free(string);
    }
    else
    {
        printf("%d\n", roman_to_integer(argv[1]));
    }

    return 0;
}

int roman_to_integer(char* str)
{
    int result = 0;
    int current = 0;
    int next = 0;

    while (*str)
    {
        switch(*str)
        {
            case 'I': current = 1; break;
            case 'V': current = 5; break;
            case 'X': current = 10; break;
            case 'L': current = 50; break;
            case 'C': current = 100; break;
            case 'D': current = 500; break;
            case 'M': current = 1000; break;
            default:
                printf("ERROR: INVALID CHARACTERS\n");
                return -1;
        }

        switch(*(str + 1))
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
        str++;
    }

    return result;
}

const struct
{
    char *symbol;
    int value;
} roman_map[13] =
{
    { "M",   1000 }, { "CM",  900 }, { "D",  500 }, { "CD",  400 },
    { "C",   100  }, { "XC",  90  }, { "L",  50  }, { "XL",  40  },
    { "X",   10   }, { "IX",  9   }, { "V",  5   }, { "IV",  4   },
    { "I",   1    }
};

void integer_to_roman(char* ptr_str, int* ptr_num)
{
    for (int i = 0; i < 13; ++i)
    {
        while (*ptr_num >= roman_map[i].value)
        {
            *ptr_num -= roman_map[i].value;
            strcat(ptr_str, roman_map[i].symbol);
        }
    }
}

int is_integer(const char* arg, int* ptr_num)
{
    if (arg == NULL || *arg == '\0')
    {
        return 0;
    }

    int temp_num = 0;
    int i = 0;

    while (arg[i] != '\0')
    {
        if (arg[i] < '0' || arg[i] > '9')
        {
            return 0;
        }

        temp_num = (temp_num * 10) + (arg[i] - '0');
        ++i;
    }

    *ptr_num = temp_num;

    return 1;
}