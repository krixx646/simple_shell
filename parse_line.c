#include "shell.h"

/**
 * parse_line - parse strings.
 * @string: string to be parse.
 *
 * Return: a pointer.
 */
char **parse_line(char *string)
{
	char *toks, **tooks;
	unsigned int ptp;

	tooks = malloc(sizeof(char) * BUFFER);

	if (tooks == NULL)
	{
		write(STDERR_FILENO, "Unable to parse\n", 16);
		exit(EXIT_FAILURE);
	}

	toks = strtok(string, "\n\t\r ");

	for (ptp = 0; toks != NULL; ptp++)
	{
		tooks[ptp] = toks;
		toks = strtok(NULL, "\n\t\r ");
	}
	tooks[ptp] = NULL;

	return (tooks);
}
