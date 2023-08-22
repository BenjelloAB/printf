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
/**
 * _printf - clones printf function
 * @...: list of arguments
 * @format: pointer to char
 * Return: int
 */

int _printf(const char *format, ...)
{
	va_list ptr;
	int i, count, sk;

	i = 0;
	count = 0;
	if (format == NULL)
		return (-1);
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			break;
		if (format[i] == '%' && format[i + 1] == '%')
		{
			print_char(format[i], &count);
			i += 2;
			continue;
		}
		if (format[i] == '%')
		{
			sk = checker_empty(&format[i + 1]);
			if (sk != -1)
			{
				i += sk + 1;
				_printer(format, ptr, i, &count);
			}
			break;
		}
		else
			print_char(format[i], &count);
		i++;
	}
	va_end(ptr);
	return (count);
}
