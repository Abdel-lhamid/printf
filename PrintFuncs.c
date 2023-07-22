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
        return (-1);

    while (str[i] != '\0')
    {
        _putchar(str[i]);
        i++;
    }

    return (i);
}
