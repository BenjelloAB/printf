#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>


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
/**
 * hand_sp - function that handles the specifier
 * @f: holds the current char pointer
 * @list:  list of variadic args
 * @i: curr index
 * @c: pointer to a counter
 * @sp: array of spcifiers
 * @sc: counter of speicifiers
 * Return: int
 */
int hand_sp(const char *f, int i, va_list list, int *c, print_t *sp, int sc)
{
	int j, sk;

	for (j = 0; j < sc; j++)
	{
		if (f[i + 1] == *(sp[j].symbol))
		{
		sp[j].printer(list, c);
		return (2);
		}
	}
	/* checking for spaces to skip em*/
	if (f[i + 1] == ' ')
	{
		sk = checker_empty(&f[i + 1]);
		if (sk != -1)
		{
			i += sk + 1;
			for (j = 0; j < sc; j++)
			{
				if (f[i] == *(sp[j].symbol))
				{
					sp[j].printer(list, c);
					return (sk + 2);
				}
			}
		}
		else
			return (-1);
	}
	write(1, &f[i + 1], 1);
	(*c)++;
	return (2);
}

/**
 * _printf - clones the printf function in stdio.h
 * @format: pointer holding the string with all formats identifiers and others
 * @...: the list of arguments passed
 * Return: int
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0, spec_count = 2, skip;

	print_t specifiers[] = {{"c", print_char}, {"s", print_str}};

	va_list list;

	if (format == NULL)
		return (-1);
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			break;
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			if (format[i + 1] == '%')
			{
				write(1, &format[i + 1], 1);
				count++;
				i += 2;
				continue;
			}
			skip = hand_sp(format, i, list, &count, specifiers, spec_count);
			if (skip == -1)
				break;
			i += skip;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
	}
	va_end(list);
	return (count);
}
