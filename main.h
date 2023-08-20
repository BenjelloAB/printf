#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct identifiers - modelize the symbols and corresponding functions
 * @symbol: holds the symbol string
 * @printer: pointer to function
 */
struct identifiers
{
	char *symbol;
	void (*printer)(va_list, int *);
};
/**
 * print_t - Typedef for strcut identifiers
 */
typedef struct identifiers print_t;

void print_char(va_list list, int *count);
void print_str(va_list list, int *count);

/* table hodling the symbols an their corseponding functions */
print_t specifiers[] = {
	{"c", print_char},
	{"s", print_str}
};

int _printf(const char *format, ...);



#endif
