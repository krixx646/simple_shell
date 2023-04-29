#include "shell.h"

/**
 * getline_func - get users line.
 * Return: input.
 */
char *getline_func(void)
{
	char *h = 0;
	int l, buffer = BUFFER, qat;
	char *boff = malloc(buffer);

	if (boff == NULL)
	{
		free(boff);
		return (NULL);
	}
	while (h != EOF && h != '\n')
	{
		fflush(stdin);
		qat = read(STDIN_FILENO, &h, 1);
		if (qat == 0)
		{
			free(boff);
			exit(EXIT_SUCCESS);
		}
		boff[l] = h;
		if (boff[0] == '\n')
		{
			free(boff);
			return ("\0");
		}
		if (l >= buffer)
		{
			boff = _realoc(boff, buffer, buffer + 1);
			if (boff == NULL)
			{
				return (NULL);
			}
		}
		l++;
	}
	boff[l] = '\0';
	handle_hash(boff);
	return (boff);
}

/**
 * handle_hash - handles hash.
 * @boff: data.
 *
 * Return: no return.
 */
void handle_hash(char boff)
{
	int abeg = 0;

	while (boff[abeg] != '\0')
	{
		if (boff[abeg] == '#')
		{
			boff[abeg] = '\0';
			break;
		}
	}
}

/**
 * echo_cmd - execute echo.
 * @edict: cmd.
 *
 * Return: 0 or -1 if fail.
 */
int echo_cmd(char **edict)
{
	int fod;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", edict, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &fod, WUNTRACED);
		} while (!WIFEXITED(fod) && !WIFSIGNALED(fod));
	}
	return (1);
}
