#include "shell.h"
/**
 * main - start of function.
 * @argc: numbers of command.
 * @argv: array of strings.
 *
 * Return: always 0 (SUCCESS).
 */
int main(int argc, char **argv)
{
	char *prompt;
	char *input, *command;
	int status = EXIT_SUCCESS;

	setenv("TERM", "xterm-256color", 1);
	prompt = "simple_shell$ ";
	while (1)
	{
		_print_prompt(prompt);
		input = _read_input();
		if (_strlen(input) == 0)
		{
			continue;
		}
		argc = _parse_input(input, argv);
		command = argv[0];
		if (_strcmp(command, "exit") == 0)
		{
			if (argc > 1)
			{
				status = atoi(argv[1]);
			}
			free(input);
			exit(status);
		}
		if (_strcmp(command, "env") == 0)
		{
			env_builtin(environ);
			continue;
		}

		_execute_command(command, argv);
		free(input);
	}
	return (0);
}
