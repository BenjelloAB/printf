#include "main.h"
int _printer(const char *s, va_list ptr, int *i, int *count);

/**
 * _printf - clones printf function
 * @...: list of arguments
 * @format: pointer to char
 * Return: int
 */
int _printf(const char *s, ...)
{
	va_list ptr;

	int i, sk, n, count;

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
			i++;
			sk = _printer(s, ptr, &i, &count);
			if (sk == -1)
				return (count);
		}
		else
			print_char(s[i], &count);
		i++;
	}
	va_end(ptr);
	return (count);
}
