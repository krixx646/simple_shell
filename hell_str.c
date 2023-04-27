#include "shell.h"

/**
 * _strcpy - copies strings.
 * @dest: destination.
 * @src: source string.
 *
 * Return: pointer.
 */
char *_strcpy(char *dest, const char *src)
{
	size_t m;

	for (m = 0; src[m] != '\0'; m++)
	{
		dest[m] = src[m];
	}
	dest[m] = '\0';
	return (dest);
}

/**
 * _strlen - Copies string.
 * @str: the string.
 *
 * Return: pointer.
 */
int _strlen(const char *str)
{
	int count = 0;

	if (!str)
	{
		return (count);
	}

	while (str[count])
		count++;

	return (count);
}

/**
 * _strchr - search a char in str.
 * @str: searched str.
 * @ch: searched char.
 *
 * Return: pointer on SUCCESS or NULL if error.
 */
char *_strchr(char *str, char ch)
{
	int sect;

	for (sect = 0; str[sect]; sect++)
	{
		if (str[sect] == ch)
		{
			return (str + sect);
		}
	}
	return (NULL);
}

/**
 * _strcmp - Compares strings.
 * @str1: first string.
 * @str2: second string.
 *
 * Return: the compare str.
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
	{
		return (*str1 - *str2);
	}
	return (0);
}
