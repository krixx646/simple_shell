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
 * @str2: first string.
 * @str1: second string.
 * @count: lenght.
 *
 * Return: the compare str.
 */
int _strcmp(char *str2, char *str1, unsigned int count)
{
	unsigned int cunt;
	unsigned int ta;

	cunt = _strlen(str1);
	if (cunt != count)
		return (-1);

	for (ta = 0; str2[ta] != '\0' && str1[ta] != '\0'; ta++)
	{
		if (str2[ta] != str1[ta])
		{
			return (1);
		}
	}
	return (0);
}

/**
 * _isalpha - search for alpha.
 * @i: alphabeth.
 *
 * Return: int.
 */
int _isalpha(int i)
{
	if (((i >= 97) && (i <= 122)) || ((i >= 65) && (i <= 90)))
	{
		return (1);
	}
	else
		return (0);
}
