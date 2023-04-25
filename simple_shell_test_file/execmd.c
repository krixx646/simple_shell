#include "shell.h"
/**
 * _print_prompt - prints prompt.
 * @prompt: shell prompt.
 *
 * Return: no return.
 */
void _print_prompt(char *prompt)
{
	write(STDOUT_FILENO, prompt, _strlen(prompt));
}

/**
 * _read_input - reads user input.
 *
 * Return: pointer.
 */
char *_read_input()
{
	char *input = NULL;
	size_t lenght = 0;
	ssize_t rd_lenght;

	rd_lenght = getline(&input, &lenght, stdin);
	if (rd_lenght == -1)
	{
		write(STDOUT_FILENO, "Terminating shell...\n", 21);
		exit(-1);
	}
	input[rd_lenght - 1] = '\0';
	return (input);
}

/**
 * _parse_input:  tokensise input.
 * @input: user input.
 * @argv: array of string.
 *
 * Return: an int.
 */
int _parse_input(char *input, char **argv)
{
	int cnt = 0;
	char *tok, *new_line = " \t\n";

	tok = strtok(input, new_line);

	while (tok != NULL && cnt < MAX_ARGV)
	{
		argv[cnt] = tok;
		cnt++;
		tok = strtok(NULL, new_line);
	}
	argv[cnt] = NULL;

	if (cnt == 0)
	{
		perror("unable to tokenize user input.\n");
		exit(-1);
	}
	return (cnt);
}

/**
 * _find_command - find users command.
 * @command: command to be found.
 *
 * Return: a pointer.
 */
char *_find_command(char *command)
{
	char *pat, *pat_cpy, *dir, *cmd_pat, *al_pat;

	if (access(command, X_OK) == 0)
	{
		return (strdup(command));
	}

	pat = getenv("PATH");
	pat_cpy = _strdup(pat);
	dir = strtok(pat_cpy, ":");
	cmd_pat = NULL;

	while (dir != NULL && cmd_pat == NULL)
	{
		al_pat = malloc(_strlen(dir) + _strlen(command) + 2);

		if (al_pat == NULL)
		{
			write(STDOUT_FILENO, "Error: failed to allocate memory.\n", 35);
			exit(-1);
		}
		sprintf(al_pat, "%s/%s", dir, command);

		if (access(al_pat, X_OK) == 0)
		{
			cmd_pat = _strdup(al_pat);
		}
		free(al_pat);
		dir = strtok(NULL, ":");
	}

	if (cmd_pat == NULL)
	{
		al_pat = malloc(_strlen("/bin/") + _strlen(command) + 2);
		if (al_pat == NULL)
		{
			write(STDOUT_FILENO, "Error: failed to allocate memory.\n", 35);
			exit(-1);
		}
		sprintf(al_pat, "/bin/%s", command);
		if (access(al_pat, X_OK) == 0)
		{
			cmd_pat = _strdup(al_pat);
		}
		free(al_pat);
	}
	free(pat_cpy);

	return (cmd_pat);
}


/**
 * _execute_command - execute a command.
 * @command: command to be executed.
 * @argv: array of strings.
 *
 * Return: no return.
 */
void _execute_command(char *command, char **argv)
{
	char *cmd_pat;
	int status, w;
	pid_t cat;

	cmd_pat = _find_command(command);
	if (cmd_pat == NULL)
	{
		write(STDOUT_FILENO, "Command not found:\n", 20);
		return;
	}
	cat = fork();

	if (cat == -1)
	{
		perror("fork() failed");
		exit(-1);
	}
	else if (cat == 0)
	{
		if (execve(cmd_pat, argv, environ) == -1)
		{
			perror("execve() failed");
			exit(-1);
		}
	}
	else
	{
		do {
			w = waitpid(cat, &status, WUNTRACED | WCONTINUED);
			if (w == -1)
			{
				perror("waitpid() failed");
				exit(-1);
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	free(cmd_pat);
}