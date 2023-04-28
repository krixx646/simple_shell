#include "shell.h"

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
	unsigned int pat_cnt, pop_t, t_top, vim = 0;

	while (environ[pop_t] != NULL)
		pop_t++;
	pop_cp = NULL;
	pop_cp = my_env_copyy(pop_cp, pop_t);

	t_top = _strlen((char *)tag);

	while (pop_cp[vim] != NULL)
	{
		lop = pop_cp[vim];
		kim = _strncmp((char *)tag, lop, t_top);
		if (kim == 1)
		{
			hsh = strtok(lop, "=");
			hsh = strtok(NULL, "\n ");
			if (hsh == NULL)
			{
				errors(4);
				exit(EXIT_FAILURE);
			}
			pat_cnt = _strlen(hsh);
			pat_vn = malloc(sizeof(char) * pat_cnt + 1);
			if (pat_vn == NULL)
			{
				errors(3);
				return (NULL);
			}
			pat_vn = _strcpy(pat_vn, hsh);
			_free(pop_cp, pop_t);
			return (pat_vn);
		}
		vim++;
	}
	return (NULL);
}

/**
 * my_env_copyy - copies env var.
 * @pop_py: pointer.
 * @pop_pt: argument.
 *
 * Return: dbl pointer.
 */
char **my_env_copyy(char **pop_py, unsigned int pop_pt)
{
	unsigned int cut, hps;
	char *cout;

	pop_py = malloc(sizeof(char **) * (pop_pt));
	if (pop_py == NULL)
	{
		errors(3);
		return (NULL);
	}

	hps = 0;
	while (hps < pop_pt)
	{
		cout = environ[hps];
		cut = _strlen(cout);

		pop_py[hps] = malloc(sizeof(char) * cut + 1);
		if (pop_py[hps] == NULL)
		{
			errors(3);
			return (NULL);
		}
		_strcpy(pop_py[hps], environ[hps]);
		hps++;
	}
	return (pop_py);
}
