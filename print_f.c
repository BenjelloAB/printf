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
	   /*added*/
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == '\0')
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	if (!format[i])
		return (0);
	/*added*/
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
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
				return (-1);
		}
		else
			print_char(format[i], &count);
		i++;
	}
	va_end(ptr);
	return (count);
}
