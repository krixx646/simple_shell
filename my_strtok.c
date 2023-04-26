#include "shell.h"

/**
 * my_strtok - tokenizes a string
 * @str: the string to tokenize
 * @delim: the delimiter to use
 *
 * Return: a pointer to the next token or NULL if there are no more tokens
 */
char *my_strtok(char *str, const char *delim)
{
	static char *thunder_clap;
	char *moda;

	if (str == NULL && thunder_clap == NULL)
	{
		return (NULL);
	}

	if (str != NULL)
	{
		thunder_clap = str;
	}
	moda = thunder_clap;

	while (*thunder_clap != '\0')
	{
		if (_strchr(delim, *thunder_clap) != NULL)
		{
			*thunder_clap = '\0';
			thunder_clap++;
			return (moda);
		}
		thunder_clap++;
	}

	if (*moda != '\0')
	{
		return (moda);
	}
	thunder_clap = NULL;
	return (NULL);
}
