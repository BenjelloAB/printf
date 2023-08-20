#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * _printf - clones the printf function in stdio.h
 * @format: pointer holding the string with all formats identifiers and others
 * @...: the list of arguments passed
 * Return: int
 */
int _printf(const char *format, ...)
{
	int i = 0, j = 0, count = 0;

	print_t specifiers[] = {
		{"c", print_char},
		{"s", print_str}
	};

	va_list list;

	if (format == NULL)
		return (-1);
	va_start(list, format);
	while (format[i])
	{
		j = 0;
		while (j < 2)
		{
			if (format[i] == '%' && format[i + 1] == *(specifiers[j].symbol))
			{

				i += 2;
				break;
			}
			j++;
		}

		if (format[i] == '%' && format[i + 1] == '%')
		{
			write(1, &format[i + 1], 1);
			i += 2;
			count++;
			continue;
		}
		write(1, &format[i], 1);
		count++;
		i++;
	}
	va_end(list);
	return (count);
}
