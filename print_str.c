#include <unistd.h>

/**
 * print_str - function that prints a string
 * @str: pointer to the string
 * @count: pointer tothe counter
 * Return: int
 */

int print_str(char *str, int *count)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		(*count)++;
	}
	return (1);
}
