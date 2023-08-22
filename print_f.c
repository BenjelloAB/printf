#include "main.h"
#include <stdlib.h>
void _printer(const char *s, va_list ptr, int i, int *count);

/**
 * checker_empty - check for spaces after '%'
 * @s: pointer to char
 * Return: int
 */
int checker_empty(const char *s)
{
    int i = 0;

    while (s[i] != '\0')
    {
        if (s[i] != ' ')
            return (i);
        i++;
    }
    return (-1);
}

int print_f(const char *s, ...)
{
    va_list ptr;
    int i;
    int count;
    int sk;

    i = 0;
    count = 0;
    if (s == NULL)
        return (-1);

 
    va_start(ptr, s);
    while (s[i])
    {
        if (s[i] == '%' && s[i + 1] == '\0')
            break;
        if (s[i] == '%' && s[i + 1] == '%')
        {
            print_char(s[i], &count);
            i += 2;
            continue;
        }
        if (s[i] == '%')
        {
            sk = checker_empty(&s[i + 1]);
            if (sk != -1)
            {
                i += sk + 1;
                _printer(s, ptr, i, &count);
            }
            break;
        }
        else
            print_char(s[i], &count);
        i++;
    }
    va_end(ptr);
    return (count);
}
