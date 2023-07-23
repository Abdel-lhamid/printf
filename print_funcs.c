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
 * print_int - calls printnumber
 * @ap: arguments for the format specifier
 * Return: printnumber function
 */
int print_int(va_list ap)
{
	int n = va_arg(ap);

	return (printnumber(n));
}

/**
 * printnumber - prints an int
 * @n: int to print
 * Return: number of characters printed
 */

int printnumber(int n)
{
	int i = 0;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
		i++;
	}

	if (n == 0)
	{
		_putchar('0');
		i++;
	}

	if (n / 10)
	{
		i += printnumber(n / 10);
	}

	_putchar(n % 10 + '0');
	i++;

	return (i);
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
