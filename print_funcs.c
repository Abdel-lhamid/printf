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
 * print_number - prints an int
 * @n: int to print
 * @is_negative: checks for negative
 * Return: number of characters printed
 */
int print_number(int n, int is_negative)
{
	int i = 0, num_digits = 0, temp = n;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	do {
		temp /= 10;

		num_digits++;
	} while (temp != 0);
	if (is_negative)
	{
		num_digits--;
	}
	while (num_digits++ < 5)
		_putchar('0');
	int divisor = 1;

	for (int j = 1; j < num_digits; j++)
		divisor *= 10;
	while (divisor >= 1)
	{
		int digit = n / divisor;

		_putchar(digit + '0');
		i++;
		n %= divisor;
		divisor /= 10;
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
	int n = va_arg(ap, int), i = 0, is_negative = 0;

	if (n < 0)
	{
		is_negative = 1;
		n = -n;
		i++;
		}
		i += print_number(n, is_negative);
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
