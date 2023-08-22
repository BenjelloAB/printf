#include "main.h"

/**
 * counter - function.
 * @s: pointer to string.
 * Return: int.
 */
int counter(const char *s)
{
	int i;

	int n;

	i = 0;
	n = 0;
	if (s[i] == '%')
	{
		n++;
		i++;
	}
	while (s[i])
	{
		if (s[i] == '%' && s[i - 1] != '%')
			n++;
		i++;
	}
	return (n);
}
