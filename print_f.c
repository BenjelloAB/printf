#include "main.h"
int _printer(const char *s, va_list ptr, int *i, int *count);

/**
 * _printf - clones printf function
 * @...: list of arguments
 * @format: pointer to char
 * Return: int
 */
int _printf(const char *format, ...)
{
	va_list ptr;

	int i, sk, n, count;

	i = 0;
	count = 0;
	n = counter(format);
	if (n == 0)
	{
		print_str((char *)format, &count);
		return (count);
	}
	if (format == NULL)
		return (-1);
	if (!format[i])
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
			i++;
			sk = _printer(format, ptr, &i, &count);
			if (sk == -1)
				return (count);
		}
		else
			print_char(format[i], &count);
		i++;
	}
	va_end(ptr);
	return (count);
}
