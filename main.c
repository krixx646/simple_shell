#include "shell.h"



int main(int argc, char **argv)
{
	char *prompt;
	char *input, *command;
	(void)argc;

	setenv("TERM", "xterm-256color", 1);

	prompt = "simple_shell$ ";
	
	while (1)
	{
		print_prompt(prompt);
		input = read_input();
		
		if (_strlen(input) == 0)
		{
			continue;
		}

		argc = parse_input(input, argv);
		command = argv[0];
		execute_command(command, argv);
		free(input);
	}
    return (0);
}
