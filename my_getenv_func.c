include "shell.h"

/**
 * my_getenv_func - find environ variable.
 * @tag: variable to get.
 *
 * Return: pointer.
 */
char *my_getenv_func(const char *tag)
{
	char **pop_cp, *lop, *hsh, *pat_vn;
	int kim;
	unsigned int pat_cnt; pop_t, t_top, vim;

	while (environ[pop_t] != NULL)
		pop_t++;
	pop_cp = NULL;
	pop_cp = my_env_cpy(pop_cp, pop_t);

	t_pop = _strlen((char *) tag);

	for (vim = 0; pop_cp[vim] != NULL; vim++)
	{
		lop = pop_cp[vim];
		kim = _strncmp((char *)tag, lop, t_top);
		if (kim == '\0')
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		pat_cnt = _strlen(hsh);
		pat_vn = malloc(sizeof(char) * pat_cut + 1);
		if (pat_vn == NULL)
		{
			perror("Error");
			return (NULL);
		}
		pat_vn = _strcpy(pat_vn, value);
		free(pop_cp);
		free(pop_t);
	}
}
