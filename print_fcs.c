#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * checker_empty - checks for empty slots after '%'
 * @s: pointer to the current element in the variadic list
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
	return (0);
}

/**
 * _printf - clones the printf function in stdio.h
 * @format: pointer holding the string with all formats identifiers and others
 * @...: the list of arguments passed
 * Return: int
 */
int _printf(const char *format, ...)
{
	int i = 0, j = 0, count = 0, si2, bo_ol = 0, si;

	
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
		bo_ol = 0;

		if (format[i] == '%' && format[i + 1] == '\0')
			break;
		if (format[i] == '%' && format[i + 1] == ' ')
		{
			si2 = checker_empty(&format[i + 1]);
			if (!si2)
			{
				return (count);
			}
			else
			{
				i += si2 + 1;
				bo_ol = 1;
			}

		}
		if (bo_ol == 1)
		{
			while (j < 2)
			{
				if (format[i] == *(specifiers[j].symbol))
				{
					si = specifiers[j].printer(list, &count);
					i++;
					break;
				}
				j++;
			}
		}
		if (j < 2 && bo_ol == 1)
			continue;

		j = 0;
		while (j < 2)
		{
			if (format[i] == '%' && format[i + 1] == *(specifiers[j].symbol))
			{
				si = specifiers[j].printer(list, &count);
				if (!si)
					return (-1);
				i += 2;
				break;
			}
			j++;
		}
		if (j < 2)
			continue;
		j = 0;
		while (j < 2)
		{
			if (format[i] == '%' && format[i + 1] != *(specifiers[j].symbol))
			{
				write(1, &format[i + 1], 1);
				i += 2;
				count++;
				break;
			}
			j++;
		}

		if (j < 2)
			continue;

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
