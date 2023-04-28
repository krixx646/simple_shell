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

/**
 * _strncmp - compares strings.
 * @str1: strings
 * @str2: strings
 * @count: string lenght.
 *
 * Return: 1 0r -1 if not the same.
 */
int _strncmp(char *str1, char *str2, unsigned int count)
{
	unsigned int mot;

	for (mot = 0; mot < count; mot++)
	{
		if (str1[mot] != str2[mot])
		{
			return (-1);
		}
	}
	return (1);
}
