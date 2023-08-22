#include <unistd.h>

/**
 * print_nbr - prints a string.
 * @n: integer arg.
 * @count: pointer to counter.
 * Return: void.
 */
void print_nbr(int n, int *count)
{
	char    c;

	long    x;

	x = n;
	if (x < 0)
	{
		write(1, "-", 1);
		(*count)++;
		x = x * (-1);
	}
	if (x > 9)
	{
		print_nbr(x / 10, count);
		print_nbr(x % 10, count);
	}
	else
	{
		c = x + '0';
		write(1, &c, 1);
		(*count)++;
	}
}

