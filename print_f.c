#include "main.h"
void    _printer(const char *s, va_list ptr, int i, int *count);

/**
 * _printf - function that clones printf
 * @format: pointer to a string
 * @...: list of args
 * Return: int
 */
int _printf(const char *format, ...)
{
	va_list ptr;
	int i;
	int n;
	int count;

	i = 0;
	count = 0;
	n = counter(format);
	/*added*/
	if (format == NULL)
		return (-1);
	if (format[0] == '%' && format[1] == '\0')
		return (-1);
	if (format[0] == '%' && format[1] == NULL)
		return (-1);
	/*added*/
	if (n == 0)
	{
		print_str((char *)format, &count);
		return (count);
	}
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%')
			_printer(format, ptr, ++i, &count);
	else
			print_char(format[i], &count);
		i++;
	}
	va_end(ptr);
	return (count);
}

