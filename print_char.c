#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - prints a char
 * @count: counter for num of chars
 * @list: the list of arguments
 * Return: void
 */
void print_char(va_list list, int *count)
{

	char c = va_arg(list, int);

	write(1, &c, 1);
	(*count)++;
}
