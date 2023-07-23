#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stddef.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list arg);
int print_str(va_list ap);
int printid(char c, va_list ap);
int print_int(va_list ap);
int printnumber(int n);


/**
 * struct functab - struct functions tab
 * @id: id of functions
 * @func: functions pointer
 */
typedef struct functab
{
	char id;
	int (*func)(va_list);
} funct_t;


#endif
