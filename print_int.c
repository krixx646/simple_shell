#include "shell.h"

/**
 * print_int - print int.
 * @mp: variable.
 *
 * Return: no return.
 */
void print_int(unsigned int u)
{
	unsigned int j = u;

	if ((j / 10) > 0)
		print_int(j / 10);
	_putchar(j % 10 + '0');
}

/**
 * print_dec - print int.
 * @u: variable.
 *
 * Return: no return.
 */
void print_dec(int u)
{
	unsigned int j = u;

	if (u < 0)
	{
		_putchar('-');
		j = -j;
	}
	if ((j / 10) > '0')
	{
		print_dec(j/ 10);
	}
	_putchar(j % 10 + '0');
