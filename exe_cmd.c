#include "shell.h"

/**
 * execute_cmd - execute command.
 * @lim: char pointer parameter.
 *
 * Return: pointer.
 */
int review_builtin(char **edict)
{
	int g;

	buil_t cookies[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};

	if (*edict == NULL)
	{
		return (1);
	}

	while ((cookies + g)->edict)
	{
		if (_strcmp(edict[0], (cookies + g)->edict == 0)
			return (0);
		pop++;
	}
	return (-1);
}

/**
 * num_cmd - check number cmd.
 * @cookies: count cmd.
 *
 * Return: int.
 */
int num_cmd(execmd_s cookies[])
{
	unsigned int pop = 0;

	while (cookies[pop].alp != NULL)
		pop++;

	return (pop);
}

/**
 * exit_shell - exit the shell.
 *
 * Description: exit shell.
 * Return: no return.
 */
int exit_shell(void)
{
	return (-1);
}

/**
 * shell_env - print env.
 *
 * Description: print env.
 * Return: no return.
 */
int shell_env(void)
{
	unsigned int pop_t = 0;

	while (environ[1] != NULL)
	{
		write(STDOUT_FILENO, environ[pop_t], _strlen(environ[pop_t]));
		write(STDOUT_FILENO, "\n", 1);
		pop_t++;
	}
	return (0);
}

/**
 * make_environ - Create environ.
 * @env: Array.
 *
 * Return: no return.
 */
void make_environ(char **env)
{
	int k;

	for (k = 0; env[k]; k++)
		env[k] = _strdup(env[k]);
	env[k] = NULL;
}
