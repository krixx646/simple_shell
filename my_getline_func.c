#include "shell.h"

/**
 * my_new_getline - get users line.
 * @ops: input of user.
 *
 * Return: input.
 */
char *my_new_getline(FILE *ops)
{
	char *str = NULL;
	size_t cnt;
	ssize hsh = 0;

	cnt = getline(&str, &hsh, ops);

	if (cnt == -1)
	{
		free(str);
		return (NULL);
	}
	return (str);
