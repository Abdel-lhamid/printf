#include "main.h"
#include <stdarg.h>
#include <stddef.h>
/**
 * _printf - function that produces output according to a format
 * @format: format to print
 * Return: number of char printed
 *
 */

int _printf(const char *format, ...)
{
	int char_p = 0, i, printed_idf = 0;
	va_list ap;

	va_start(ap, format);
	if (format != NULL && format[0] != '\0')
	{
		for (i = 0; format[i] != '\0'; i++)
		{
			if (format[i] != '%')
			{
				_putchar(format[i]);
				char_p++;
				continue;
			}

			if (format[i + 1] == '%')
			{
				_putchar('%');
				char_p++;
				continue;
			}
			if (format[i + 1] == '\0')
				return(-1);
			printed_idf = printid(format[i + 1], ap);
			if (print_idf == -1)
				continue;
			if (printed_idf > 0)
			{
				char_p += printed_idf;
			}
			if (printed_idf == 0)
			{
				_putchar('%');
				char_p++;
			}
		}
		return (char_p);
	}
	va_end(ap);
	return (-1);
}
