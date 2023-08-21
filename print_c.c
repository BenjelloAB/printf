#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_char - prints a char
 * @count: counter for num of chars
 * @list: the list of arguments
 * Return: void
 */
int print_char(va_list list, int *count)
{

	char c = va_arg(list, int);

	write(1, &c, 1);
	(*count)++;
	return (1);
}

/**
 * print_str - fucntion to print a string
 * @list: the arguments list
 * @count: pointer to the count variable
 * Return: void
 */

int print_str(va_list list, int *count)
{
	int i = 0;

	char *s = va_arg(list, char *);

	if (s == NULL)
		s = "(null)";
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
		(*count)++;
	}
	return (1);
}

