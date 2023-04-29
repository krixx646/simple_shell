#include "shell.h"

/**
 * _free - free.
 * @arv: char argument.
 * @arc: unsigned int argument.
 *
 * Retrun: no return.
 */
void _free(char **arv, unsigned int arc)
{
	unsigned int mee;

	for (mee = 0; mee < arc; mee++)
	{
		free(arv[mee]);
	}
	free(arv);
}

/**
 * free_up - free memory.
 * @edict: command.
 * @row: char variable.
 *
 * Return: no return.
 */
void free_up(char **edict, char *row)
{
	free(edict);
	free(row);
	edict = NULL;
	row = NULL;
}

/**
 * env_freed - frees env.
 * @env: Env variable.
 *
 * Return: no return.
 */
void env_freed(char **env)
{
	int pop = 0;

	while (env[pop])
	{
		free(env[pop]);
		i++;
	}
}
