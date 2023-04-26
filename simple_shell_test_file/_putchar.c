#include "shell.h"

/**
 * _putchar - writes the character to stdout.
 * @c: The character to print.
 *
 * Return: On success 1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putstr - prints string
 * @str: string to be print.
 *
 * Description: printing out strings
 * Return: returns output
 */
int _putstr(char *str)
{
	int len;
	int t;

	len = strlen(str);
	for (t = 0; t < len; t++)
	{
		_putchar(str[t]);
	}
	return (len);
}
