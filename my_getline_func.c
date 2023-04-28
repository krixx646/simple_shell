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
	ssize_t cnt;
	size_t hsh = 0;

	cnt = getline(&str, &hsh, ops);

	if (cnt == -1)
	{
		free(str);
		return (NULL);
	}
	return (str);
}
