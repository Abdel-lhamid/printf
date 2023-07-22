#include "main.h"
#include <stdarg.h>


/**
 *
 *
 */
int print_char(va_list ap)
{
	return (_putchar(va_arg(ap, int)));

}
int print_str(va_list ap)
{
	int i = 0;
	char *str = va_arg(ap, *char);
	
	if (str[i] == '\0' || str == NULL)
		return (-1);
	while (str[i] == '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}
/**
 *
 *
 *
 */

int _printf(const char *format, ...)
{
	int char_p = 0, i, j;
	va_list ap;

	funct_t funcs[] = { {'c', print_char},
			      {'s', print_str},
			      {'\0', NULL} };

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
			if (format[i] != 'c' && format[i] != 's')
			{
				_putchar('%');
				char_p++;
				_putchar(format[i]);
				char_p++;
				continue;
			}
			
			for (j = 0 ; funcs[j].id != '\0'; j++)
			{
				if (format[i] == funcs[j].id)
				{
					char_p += funcs[j].func(ap);
					i++;
					break;
				}
			}
			
		}
		return (char_p);
	}
	return (-1);
}
