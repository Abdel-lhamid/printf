#include "main.h"
#include <unistd.h>
#include <stdio.h>

/**
 * print_char - prints character
 * @arg: object representing the variable argument list
 *
 * Return: the number of characters printed.
 */
int print_char(va_list arg)
{
	return (_putchar(va_arg(arg, int)));
}

/**
 * print_str - prints a string
 * @ap: first variable
 * Return: number of characters printed
 */

int print_str(va_list ap)
{
	int i = 0;
	char *str = va_arg(ap, char *);

	if (str == NULL)
		str = "(null)";
	else if (*str == '\0')
		return (-1);

	while (str[i] != '\0')
	{
	_putchar(str[i]);
	i++;
	}

	return (i);
}

/**
 * print_int - prints an integer
 * @ap: arguments for the format specifier
 * Return: number of characters printed
 */

int print_int(va_list ap)
{
	unsigned int divisor = 1, i, resp, charPrinted = 0;
	int n = va_arg(ap, int);

	if (n < 0)
	{
		_putchar('-');
		charPrinted++;
		n *= -1;
	}

	for (i = 0; n / divisor > 9; i++, divisor *= 10)
		;

	for (; divisor >= 1; n %= divisor, divisor /= 10, charPrinted++)
	{
		resp = n / divisor;
		_putchar('0' + resp);
	}

	return (charPrinted);
}
/**
 * printid - checks for specifiers
 * @c: The format specifier to process.
 * @ap: arguments for the format specifier
 * Return: int
 */
int printid(char c, va_list ap)
{
	int i;
	funct_t funcs[] = {
	{'c', print_char},
	{'s', print_str},
	{'i', print_int},
	{'d', print_int},
	{'b', print_binary},
	{'\0', NULL}
	};
	for (i = 0; funcs[i].id != '\0'; i++)
		{
		if (c == funcs[i].id)
		{
		return (funcs[i].func(ap));
		}
	}
	return (0);
}
