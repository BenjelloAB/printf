#include <unistd.h>
void print_char(char c, int *count)
{
	write (1, &c, 1);
	(*count)++;
}

