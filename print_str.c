#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_str - fucntion to print a string
 * @list: the arguments list
 * @count: pointer to the count variable
 * Return: void
 */

void print_str(va_list list, int *count)
{
	int i = 0;

	char *s = va_arg(list, char *);

	if (s == NULL)
		return;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
		(*count)++;
	}
}
