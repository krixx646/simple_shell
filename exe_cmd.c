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
	unsigned int pop;
	int kim, kl = 0;

	execmd_s cookies[0] = {
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

	while (kl < vul)
	{
		if (_strcmp(lim[0], cookies[kl].alp, vul) == 0)
		{
			kim = (cookies[kl].los)();
			return (kim);
		}
		kl++;
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
