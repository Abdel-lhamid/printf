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
			i++;
			if (format[i] == '%')
			{
				_putchar('%');
				char_p++;
				continue;
			}
			printed_idf = printid(format[i], ap);

			if (printed_idf > 0)
			{
				char_p += printed_idf;
			}
			if (printed_idf == 0)
			{
				_putchar('%');
				char_p++;
				_putchar(format[i]);
				char_p++;
			}
		}
		return (char_p);
	}
	va_end(ap);
	return (-1);
}
