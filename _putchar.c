#include <unistd.h>

/**
 * _putchar - prints character
 * @c: char to print
 * Return: number of char printed
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
