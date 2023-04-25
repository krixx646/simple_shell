#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print 
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately. 
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putstr: prints out string.
 *
 * @return: returns output.
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
