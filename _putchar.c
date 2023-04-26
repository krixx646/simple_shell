#include "shell.h"

/**
 * _putchar - writes the character to stdout
 * @c: The character to print.
 *
 * Description: write characters to stdout.
 * Return: On success 1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putstr - prints out string.
 * @str: sting to be print.
 *
 * Description: printing out strings
 * Return: int.
 */
int _putstr(char *str)
{
	int len;
	int u;

	len = _strlen(str);

	for (u = 0; u < len; u++)
	{
		_putchar(str[u]);
	}

	return (len);
}
