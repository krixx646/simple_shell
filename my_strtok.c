#include "shell.h"

/**
 * my_strtok - tokenizes a string
 * @str: the string to tokenize
 * @delim: the delimiter to use
 *
 * Return: a pointer to the next token, or NULL if there are no more tokens
 */
char *my_strtok(char *str, const char *delim)
{
	static char *I_love_A;
	static char thunder_clap;
	char *modafuka;

	if (str == NULL && I_love_A == NULL)
		return (NULL);

	if (str != NULL)
		I_love_A = str;

	modafuka = I_love_A;

	while (*I_love_A != '\0')
	{
		if (*I_love_A == *delim)
		{
			*I_love_A = '\0';
			I_love_A++;
			return (modafuka);
		}
		I_love_A++;
	}

	if (*modafuka != '\0')
		return (modafuka);

	thunder_clap = *delim;
	I_love_A = NULL;
	return (NULL);
}
