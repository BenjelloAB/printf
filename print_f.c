#include "main.h"
#include <unistd.h>
#include <stdlib.h>

print_t specifiers[] = {
    {"c", print_char},
    {"s", print_str}};

int is_valid_specifier(char c)
{
    long unsigned int j;

    for (j = 0; j < sizeof(specifiers) / sizeof(specifiers[0]); j++)
    {
        if (c == *specifiers[j].symbol)
            return j;
    }
    return -1;
}

int process_valid_specifier(int index, va_list list, int *count)
{
    return specifiers[index].printer(list, count);
}

void process_non_specifier(char c, int *count)
{
    write(1, &c, 1);
    (*count)++;
}

int _printf(const char *format, ...)
{
    int i = 0, count = 0, whitespace_count, spec_index;

    va_list list;

    if (format == NULL)
        return -1;

    
    va_start(list, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '\0')
                break;
            whitespace_count = 0;
            while (format[i] == ' ')
            {
                whitespace_count++;
                i++;
            }

            if (format[i] == '\0') {
                break;
            }

            spec_index = is_valid_specifier(format[i]);
            if (spec_index != -1)
            {
                process_valid_specifier(spec_index, list, &count);
                i++;
            }
            else
            {
                process_non_specifier(format[i], &count);
                i++;
            }
        }
        else
        {
            process_non_specifier(format[i], &count);
            i++;
        }
    }

    va_end(list);
    return count;
}

