#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
int    counter(const char *s);
int    _printf(const char *s, ...);
void print_char(char c, int *count);
void    print_nbr(int n, int *count);
int print_str(char *str, int *count);
int _printer(const char *s, va_list ptr, int *i, int *count);


#endif

