#include "shell.h"

/**
 * execute_cmd - execute command.
 * @lim: char pointer parameter.
 *
 * Return: pointer.
 */
int execute_cmd(char **lim)
{
	unsigned int co;
	unsigned int vul;
	unsigned int pop = 0;
	int kim;

	execmd_s cookies[3] = {
		{"exit", exit_shell},
		{"env", shell_env},
		{NULL, NULL}
	};

	if (lim[0] == NULL)
	{
		return (1);
	}

	co = _strlen(lim[0]);

	vul = num_cmd(cookies);

	while (pop < vul)
	{
		if (_strcmp(lim[0], cookies[pop].alp, co) == 0)
		{
			kim = (cookies[pop].los)();
			return (kim);
		}
		pop++;
	}
	return (1);
}

/**
 * num_cmd - check number cmd.
 * @cookies: count cmd.
 *
 * Return: int.
 */
int num_cmd(execmd_s cookies[])
{
	unsigned int pop_t = 0;

	while (cookies[pop_t].alp != NULL)
	{
		pop_t++;
	}
	return (pop_t);
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
	unsigned int pop_t;

	while (environ[1] != NULL)
	{
		write(STDOUT_FILENO, environ[pop_t], _strlen(environ[pop_t]));
		write(STDOUT_FILENO, "\n", 1);
		pop_t++;
	}
	return (0);
}
