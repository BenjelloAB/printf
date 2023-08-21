#include "main.h"
void    _printer(const char *s, va_list ptr, int i, int *count);
int    print_f(const char *s, ...)
{
    va_list ptr;
    int i;
    int n;
    int count;

    i = 0;
    count = 0;
    n = counter(s);
    if (n == 0)
    {
        print_str((char *)s, &count);
        return (count);
    }
    va_start(ptr, s);
    while (s[i])
    {
        if (s[i] == '%')
            _printer(s, ptr, ++i, &count);
        else
            print_char(s[i], &count);
        i++;
    }
    va_end(ptr);
    return (count);
}

