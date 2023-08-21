#include "main.h"
#include <unistd.h>
#include <stdlib.h>


/**
 * is_valid_specifier - checks if the specifier is valid
 * @c: cpatures a character
 * Return: int
 */
int is_valid_specifier(char c)
{
	unsigned int long j;

	print_t specifiers[] = {
	{"c", print_char},
	{"s", print_str}};

	for (j = 0; j < 2; j++)
	{
	if (c == *specifiers[j].symbol)
		return (j);
	}
	return (-1);
}
/**
 * pvs - processes valid specs
 * @count: counter passed as pointer
 * @list:  the varaidic args list
 * @index: current index
 * Return: int
 */
int pvs(int index, va_list list, int *count)
{
	print_t specifiers[] = {
	{"c", print_char},
	{"s", print_str}};
	return (specifiers[index].printer(list, count));
}

/**
 * pns - function to process non spec
 * @c: character
 * @count: counter passed as pointer
 * Return: void
 */
int pns(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
	return (1);
}
/**
 * _printf - clones the printf function in stdio.h
 * @format: pointer holding the string with all formats identifiers and others
 * @...: the list of arguments passed
 * Return: int
 */

int _printf(const char *format, ...)
{
	int i = 0, count = 0, whitespace_count, spec_index;

	va_list list;

	if (format == NULL)
		return (-1);
	va_start(list, format);
	while (format[i])
	{
	if (format[i] == '%')
	{
		i++;
		if (format[i] == '\0')
			break;
		whitespace_count = 0;
		while (format[i] == ' ')
		{
			whitespace_count++;
			i++;
		}
		if (format[i] == '\0')
			break;
		spec_index = is_valid_specifier(format[i]);
		(spec_index != -1) ? pvs(spec_index, list, &count) : pns(format[i], &count);
		i++;
	}
	else
	{
		pns(format[i], &count);
		i++;
	}
	}
	va_end(list);
	return (count);
}
