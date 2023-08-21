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
	int (*printer)(va_list, int *);
};
/**
 * print_t - Typedef for strcut identifiers
 */
typedef struct identifiers print_t;

int print_char(va_list list, int *count);
int print_str(va_list list, int *count);


int _printf(const char *format, ...);

extern print_t specifiers[];


#endif
