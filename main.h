#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>


int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list arg);
int print_str(va_list ap);

typedef struct functab
{
	char id;
	int (*func)(va_list);
} funct_t;


#endif
