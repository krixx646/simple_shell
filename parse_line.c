#include "shell.h"

/**
 * parse_line - parse strings.
 * @data: string to be parse.
 *
 * Return: a pointer.
 */
char **parse_line(char *data)
{
	char *toks, **tooks;
	int p, boff = BUFFER;

	if (tooks == NULL)
	{
		return (NULL);
	}

	tooks = malloc(sizeof(char *) * boff);
	if (!tooks)
	{
		perror("Error");
		return (NULL);
	}
	toks = _strtok(data, "\n ");
	for (p = 0; toks; p++)
	{
		tooks[p] = toks;
		toks = _strtok(NULL, "\n ");
	}
	tooks[p] = NULL;

	return (tooks);
}
