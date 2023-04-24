#include "shell.h"

/**
 * strlen - Calculates the length of a string
 * @str: The string to be measured
 *
 * Return: The length of the string
 */

size_t strlen(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;

	return (i);
}

/**
 * strchr - Locates a character in a string
 * @str: The string to be searched
 * @c: The character to be located
 *
 * Return: A pointer to the first occurrence of the character c in the string
 * str, or NULL if the character is not found
 */

char *strchr(const char *str, int c)
{
	char *ptr = NULL;
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == c)
		{
			ptr = (char *)&str[i];
			break;
		}
	}

	return (ptr);
}
