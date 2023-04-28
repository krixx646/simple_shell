#include "shell.h"

/**
 * my_getline_func - get users line.
 * @ops: input of user.
 *
 * Return: input.
 */
char *my_getline_func(FILE *ops)
{
	char *str = NULL;
	ssize_t read;
	size_t hsh = 0;

	read = getline(&str, &hsh, ops);

	if (read == -1)
	{
		free(str);
		return (EXIT_SUCCESS);
	}
	return (str);
}
