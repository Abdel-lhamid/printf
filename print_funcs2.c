#include <unistd.h>
#include <stdio.h>
#include "main.h"

/**
 * print_binary - Prints the binary representation of an unsigned integer.
 * @ap: A va_list pointing to the argument to be printed.
 *
 * Return: The number of characters printed.
 */

int print_binary(va_list ap)
{
	unsigned int num = va_arg(ap, unsigned int);
	int printed = 0;

	if (num == 0)
	{
		_putchar('0');
		printed++;
	}
	else
	{
		print_binary_recursive(num, &printed);
	}
	return (printed);
}

/**
 * print_binary_recursive - Recursively prints the binary representation
 *                          of an unsigned integer.
 * @n: The unsigned integer to be printed in binary.
 * @printed: A pointer to keep track of the number of characters printed.
 *
 * Return: void
 */

void print_binary_recursive(unsigned int n, int *printed)
{
	if (n > 1)
	{
		print_binary_recursive(n >> 1, printed);
	}

	_putchar((n & 1) + '0');
	(*printed)++;
}
