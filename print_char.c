#include <unistd.h>
/**
 * print_char - function to print a char.
 * @c: a character.
 * @count: pointer to counter.
 * Return: void.
 */
void print_char(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}
