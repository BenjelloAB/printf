#include "main.h"
/**
 * checker_empty - function thaat prints according to spec
 * @s: pointer to the given string
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
 * _printer - function thaat prints according to spec
 * @s: pointer to the given string
 * @ptr: ptr to the list of variadic arguments
 * @i: integer for curr index
 * @count: pointer to the counter
 * Return: void
 */
int _printer(const char *s, va_list ptr, int *i, int *count)
{
	int sk;

	if (s[*i] == 'c')
		print_char(va_arg(ptr, int), count);
	else if (s[*i] == 's')
	{
		if (!print_str(va_arg(ptr, char *), count))
			print_str("(null)", count);
	}
	else if (s[*i] == 'd' || s[*i] == 'i')
		print_nbr(va_arg(ptr, int), count);
	else if (s[*i] == ' ')
	{
		sk = checker_empty(&s[(*i) + 1]);
		if (sk != -1)
		{
			*i =  (*i) + sk + 1;
			_printer(s, ptr, i, count);
		}
		else
			return (-1);
	}
	else
	{
		print_char(s[(*i) - 1], count - 1);
		print_char(s[*i], count);
	}
	return (1);
}
