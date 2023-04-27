#include "shell.h"

/**
 * _strcat - Concantenate two strings.
 * @dest: dest string.
 * @src: source string.
 *
 * Return: pointer.
 */
char *_strcat(char *dest, const char *src)
{
	const char *container1;
	char *container;

	container1 = src;
	container = dest;

	while (*container1 != '\0')
		container1++;

	while (*container !=  '\0')
		*container++ = *container1++;
	*container = '\0';
	return (dest);
}
