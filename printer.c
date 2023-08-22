#include "main.h"
/**
 * _printer - function thaat prints according to spec
 * @s: pointer to the given string
 * @ptr: ptr to the list of variadic arguments
 * @i: integer for curr index
 * @count: pointer to the counter
 * Return: void
 */
void _printer(const char *s, va_list ptr, int i, int *count)
{
	if (s[i] == 'c')
		print_char(va_arg(ptr, int), count);
	else if (s[i] == 's')
	{
		if (!print_str(va_arg(ptr, char *), count))
			print_str("(null)", count);
	}
	else if (s[i] == 'd' || s[i] == 'i')
		print_nbr(va_arg(ptr, int), count);
	else
		print_char(s[i], count);
}
