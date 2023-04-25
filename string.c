#include "shell.h"

/**
 * _strcmp - compares two strings.
 * @str1: first string.
 * @str2: second string.
 *
 * Return: result of the two string.
 */
int _strcmp(char *str1, char *str2)
{
	int h = 0, end_result;

	while (*(str1 + h) == *(str2 + h) && *(str1 + h) != '\0')
		h++;

	end_result = (*(str1 + h) - *(str2 + h));

	return (end_result);
}

/**
 * _strdup - duplicate a string.
 * @string: string to be duplicated.
 *
 * Return: a pointer.
 */
char *_strdup(char *string)
{
	char *ops;
	int v, lenght;

	if (string == NULL)
	{
		return (NULL);
	}

	lenght = _strlen(string);

	ops = malloc(sizeof(char) *(lenght + 1));
	if (!ops)
		return (NULL);
	for (v = 0; *string != '\0'; string++, v++)
	{
		ops[v] = string[0];
	}
	ops[v++] = '\0';

	return(ops);
}

/**
 * _strlen - returns lenght of string.
 * @str: string.
 *
 * Return: int.
 */
int _strlen(char *str)
{
	int num = 0;

	while (*str != '\0')
	{
		num++;
		str++;
	}
	return (num);
}

/**
 * _strchr - search for character in a string.
 * @str: string to checked.
 * @ch: character.
 *
 * Return: pointer or NULL if not seen.
 */
char *_strchr(char *str, char ch)
{
	while (*str)
	{
		if (*str == ch)
		{
			return (str);
		}
		str++;
	}
	if (!ch)
	{
		return(str);
	}
	return (NULL);
}
