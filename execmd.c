#include "shell.h"

/**
 * execute_command -  execute the file.
 * @cmd: a char double pointer.
 *
 * Return: no return.
 */
void execute_command(char **cmd)
{
	char *exe = NULL;

	if (cmd)
	{
		exe = cmd[0];
		if (execve(exe, cmd, NULL) == -1)
		{
			perror("Error:");
		}
	}
}
